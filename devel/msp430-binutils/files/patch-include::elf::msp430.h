--- include/elf/msp430.h	2002-12-31 03:25:12.000000000 +0800
+++ include/elf/msp430.h	2003-08-06 01:51:10.000000000 +0800
@@ -24,23 +24,24 @@
 #include "elf/reloc-macros.h"
 
 /* Processor specific flags for the ELF header e_flags field.  */
 #define EF_MSP430_MACH 		0xff
 
-#define E_MSP430_MACH_MSP430x11x1  110
 #define E_MSP430_MACH_MSP430x11  11
+#define E_MSP430_MACH_MSP430x11x1  110
 #define E_MSP430_MACH_MSP430x12  12
 #define E_MSP430_MACH_MSP430x13  13
 #define E_MSP430_MACH_MSP430x14  14
+#define E_MSP430_MACH_MSP430x15  15
+#define E_MSP430_MACH_MSP430x16  16
 #define E_MSP430_MACH_MSP430x31  31
 #define E_MSP430_MACH_MSP430x32  32
 #define E_MSP430_MACH_MSP430x33  33
 #define E_MSP430_MACH_MSP430x41  41
+#define E_MSP430_MACH_MSP430x42  42
 #define E_MSP430_MACH_MSP430x43  43
 #define E_MSP430_MACH_MSP430x44  44
-#define E_MSP430_MACH_MSP430x15  15
-#define E_MSP430_MACH_MSP430x16  16
 
 /* Relocations.  */
 START_RELOC_NUMBERS (elf_msp430_reloc_type)
      RELOC_NUMBER (R_MSP430_NONE,		0)
      RELOC_NUMBER (R_MSP430_32,			1)
