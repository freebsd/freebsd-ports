--- include/cpu_f77blas.h.orig	2023-10-13 13:10:15 UTC
+++ include/cpu_f77blas.h
@@ -13,7 +13,7 @@
   #define GCTA_ARCH_i386 0
 #endif
 
-#if GCTA_ARCH_x86_64 || GCTA_ARCH_i386
+#if !defined(__FreeBSD__) && (GCTA_ARCH_x86_64 || GCTA_ARCH_i386)
   #define GCTA_CPU_x86 1
 #else
   #define GCTA_CPU_x86 0
@@ -46,4 +46,4 @@
   #include <f77blas.h>
 #endif
 
-#endif  //END GCTA_F77BLAS_CPU_H
\ No newline at end of file
+#endif  //END GCTA_F77BLAS_CPU_H
