--- include/elf/mips.h.orig	2005-05-10 11:21:10.000000000 +0100
+++ include/elf/mips.h	2007-02-08 20:06:04.000000000 +0000
@@ -212,6 +212,7 @@
 #define E_MIPS_MACH_5400	0x00910000
 #define E_MIPS_MACH_5500	0x00980000
 #define E_MIPS_MACH_9000	0x00990000
+#define E_MIPS_MACH_ALLEGREX	0x00A20000
 
 /* Processor specific section indices.  These sections do not actually
    exist.  Symbols with a st_shndx field corresponding to one of these
