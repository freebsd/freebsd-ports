--- bfd/elf32-nds32.c.orig	2014-02-07 13:04:20.389741513 +0100
+++ bfd/elf32-nds32.c	2014-02-07 13:06:47.079732839 +0100
@@ -6303,7 +6303,7 @@
 			     int *pinsn_type)
 {
   uint16_t insn16 = 0;
-  int insn_type;
+  int insn_type = 0;
   unsigned long mach = bfd_get_mach (abfd);
 
   if (N32_SH5 (insn) != 0)
@@ -6518,7 +6518,7 @@
 {
   int op6;
   uint16_t insn16 = 0;
-  int insn_type;
+  int insn_type = 0;
   unsigned long mach = bfd_get_mach (abfd);
 
   /* Decode 32-bit instruction.  */
