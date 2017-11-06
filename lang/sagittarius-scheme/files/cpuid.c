#include <stdio.h>

const char *s_edx[] = { "FPU", "VME", "DE", "PSE", "TSC", "MSR",
					   "PAE", "MCE", "CX8", "APIC", NULL, "SEP",
					   "MTRR", "PGE", "MCA", "CMOV", "PAT", "PSE36",
					   "PSN", "CLFLUSH", NULL, "DTS", "ACPI", "MMX",
					   "FXSR", "SSE", "SSE2", "SS", "HTT", "TM",
					   "IA64", "PBE" };

const char *s_ecx[] = { "SSE3", "PCLMULQDQ", "DTES64", "MON", "DS_CPL", "VMX",
					   "SMX", "EST", "TM2", "SSSE3", "CNXT_ID", "SDBG",
					   "FMA", "CX16", "XTPTR", "PDCM", NULL, "PCID", "DCA",
					   "SSE4.1", "SSE4.2", "x2APIC", "MOVBE", "POPCNT",
					   "TSCDLT", "AESNI", "XSAVE", "OSXSAVE", "AVX", "F16C",
					   "RDRAND", "HYPERVISOR" };

#define PRINT_REG(reg) 	for (f = 1, i = 0; i < 32; i++, f <<= 1 ) { \
	if( NULL != s_##reg[i] ) { \
			if( (reg & f) == f) { \
				if( i !=0 ) \
					putchar(','); \
				printf( "%s", s_##reg[i] ); \
			} \
		} \
	}


int
main()
{
	int edx, ecx;
	int i, f;

	__asm__("cpuid" : "=c"(ecx), "=d"(edx) : "a"(1));

	printf( "Features=0x%x<", edx );
	PRINT_REG(edx);
	puts(">");
	printf( "Features2=0x%x<", ecx );
	PRINT_REG(ecx);
	puts(">");
}
