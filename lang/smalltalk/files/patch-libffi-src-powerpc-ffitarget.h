
--- libffi/src/powerpc/ffitarget.h.orig	2010-10-08 21:22:55.000000000 +0200
+++ libffi/src/powerpc/ffitarget.h	2010-10-08 21:23:39.000000000 +0200
@@ -78,6 +78,8 @@
   FFI_SYSV,
   FFI_GCC_SYSV,
   FFI_LINUX64,
+  FFI_LINUX,
+  FFI_LINUX_SOFT_FLOAT,
   FFI_DEFAULT_ABI = FFI_SYSV,
 #endif
 


