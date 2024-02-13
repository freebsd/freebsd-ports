--- libs/context/src/asm/jump_i386_sysv_elf_gas.S.orig	2023-12-06 21:03:02 UTC
+++ libs/context/src/asm/jump_i386_sysv_elf_gas.S
@@ -24,6 +24,10 @@
  *                                                                                      *
  ****************************************************************************************/
 
+#ifdef __x86_64__
+#include "jump_x86_64_sysv_elf_gas.S"
+#else
+
 .file "jump_i386_sysv_elf_gas.S"
 .text
 .globl jump_fcontext
@@ -91,3 +95,5 @@ jump_fcontext:
 
 /* Mark that we don't need executable stack.  */
 .section .note.GNU-stack,"",%progbits
+
+#endif
