--- Modules/_ctypes/libffi/src/powerpc/ffitarget.h.orig 2009-12-28 12:29:03.000000000 +0000
+++ Modules/_ctypes/libffi/src/powerpc/ffitarget.h      2009-12-28 12:30:11.000000000 +0000
@@ -78,6 +78,8 @@
   FFI_SYSV,
   FFI_GCC_SYSV,
   FFI_LINUX64,
+  FFI_LINUX,
+  FFI_LINUX_SOFT_FLOAT,
   FFI_DEFAULT_ABI = FFI_SYSV,
 #endif
