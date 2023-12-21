--- aarch64-asm.S.orig	2016-03-30 04:42:59 UTC
+++ aarch64-asm.S
@@ -123,3 +123,5 @@ asm_function aligned_block_copy_ld1st1_aarch64
 .endfunc
 
 #endif
+
+.section .note.GNU-stack,"",@progbits
