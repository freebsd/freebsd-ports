--- mips-32.S.orig	2016-03-30 04:42:59 UTC
+++ mips-32.S
@@ -181,3 +181,5 @@ asm_function aligned_block_copy_pf32_mips32
 .endfunc
 
 #endif
+
+.section .note.GNU-stack,"",@progbits
