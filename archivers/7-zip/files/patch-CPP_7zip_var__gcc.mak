--- CPP/7zip/var_gcc.mak.orig	2021-12-10 10:31:55 UTC
+++ CPP/7zip/var_gcc.mak
@@ -6,7 +6,7 @@ IS_ARM64=
 CROSS_COMPILE=
 MY_ARCH=
 USE_ASM=
-CC=$(CROSS_COMPILE)gcc
-CXX=$(CROSS_COMPILE)g++
+CC=$(CC)
+CXX=$(CXX)
 
 # -march=armv8-a+crc+crypto
