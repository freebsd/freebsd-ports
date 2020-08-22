--- asmrun/amd64.S.orig	2020-08-22 20:02:29 UTC
+++ asmrun/amd64.S
@@ -725,7 +725,7 @@ G(caml_system__spacetime_shapes):
 #elif defined(SYS_mingw64) || defined(SYS_cygwin)
         .section .rdata,"dr"
 #else
-        .section    .rodata.cst8,"a",@progbits
+        .section    .rodata.cst8,"aM",@progbits,8
 #endif
         .globl  G(caml_negf_mask)
         .align  SIXTEEN_ALIGN
