--- libs/context/src/asm/make_i386_sysv_elf_gas.S.orig	2023-12-06 21:03:02 UTC
+++ libs/context/src/asm/make_i386_sysv_elf_gas.S
@@ -24,6 +24,10 @@
  *                                                                                      *
  ****************************************************************************************/
 
+#ifdef __x86_64__
+#include "make_x86_64_sysv_elf_gas.S"
+#else
+
 .file "make_i386_sysv_elf_gas.S"
 .text
 .globl make_fcontext
@@ -111,3 +115,5 @@ finish:
 
 /* Mark that we don't need executable stack.  */
 .section .note.GNU-stack,"",%progbits
+
+#endif
