--- Modules/_ctypes/libffi/src/powerpc/ffitarget.h.orig	2011-11-16 20:32:42.000000000 -0800
+++ Modules/_ctypes/libffi/src/powerpc/ffitarget.h	2011-11-16 20:33:23.000000000 -0800
@@ -78,6 +78,8 @@
   FFI_SYSV,
   FFI_GCC_SYSV,
   FFI_LINUX64,
+  FFI_LINUX,
+  FFI_LINUX_SOFT_FLOAT,
   FFI_DEFAULT_ABI = FFI_SYSV,
 #endif
 
