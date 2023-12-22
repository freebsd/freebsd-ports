--- x86-sse2.S.orig	2016-03-30 04:42:59 UTC
+++ x86-sse2.S
@@ -243,3 +243,5 @@ asm_function aligned_block_fill_nt_sse2
 /*****************************************************************************/
 
 #endif
+
+.section .note.GNU-stack,"",@progbits
