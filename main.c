#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

union Data {
	uint8_t u8[8];
	uint16_t u16[4];
	uint32_t u32[2];
	uint64_t u64;
};

int main(int argc, char** argv) {
	int quit = 1;
	union Data data;
	char output[74]; //eg. 0b10000001'00000000'01010100'00001000'00010100'00010001'00100001'00000001\0
	output[0] = '0';
	output[1] = 'b';
	output[10] = 39; //character '
	output[19] = 39;
	output[28] = 39;
	output[37] = 39;
	output[46] = 39;
	output[55] = 39;
	output[64] = 39;
	output[73] = 0; //null byte
	uint8_t mask = 0b10000000;
	while (quit != 0) {
		printf("hex bytes to binary. (0 to quit, 1 to continue): ");
		scanf("%d", &quit);
		if (quit == 0)
			return 0;
		printf("8 bytes in hex (space separated): ");
		scanf("%2hhx %2hhx %2hhx %2hhx %2hhx %2hhx %2hhx %2hhx", &data.u8[7], &data.u8[6], &data.u8[5], &data.u8[4], &data.u8[3], &data.u8[2], &data.u8[1], &data.u8[0]);
		size_t currentOutputElement = 1;
		for (size_t currentDataElement = 0; currentDataElement < 8; ++currentDataElement) {
			currentOutputElement += 1;
			for (int currentBit = 0; currentBit < 8; ++currentBit) {
				output[currentOutputElement] = (((data.u8[currentDataElement] << currentBit) & mask) >> 7) + 48;
				currentOutputElement += 1;
			}
		}
		printf("output: %s\n", output);
	}
	return 0;
}
