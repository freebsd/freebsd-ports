--- arm-neon.S.orig	2016-03-30 04:42:59 UTC
+++ arm-neon.S
@@ -473,3 +473,5 @@ asm_function aligned_block_copy_vfp
 .endfunc
 
 #endif
+
+.section .note.GNU-stack,"",@progbits
