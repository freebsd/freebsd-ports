--- include/cpu.h.orig	2022-08-03 06:01:52 UTC
+++ include/cpu.h
@@ -13,7 +13,8 @@
   #define GCTA_ARCH_i386 0
 #endif
 
-#if GCTA_ARCH_x86_64 || GCTA_ARCH_i386
+// GCTA_ARCH_x86 is used (mostly) to enable Intel's MKL library
+#if !defined(__FreeBSD__) && (GCTA_ARCH_x86_64 || GCTA_ARCH_i386)
   #define GCTA_CPU_x86 1
 #else
   #define GCTA_CPU_x86 0
@@ -50,4 +51,4 @@
   #include <lapack.h>
 #endif
 
-#endif  //END GCTA_CPU_H
\ No newline at end of file
+#endif  //END GCTA_CPU_H
