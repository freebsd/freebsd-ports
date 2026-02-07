--- 3rdparty/lzma/CPP/7zip/var_gcc.mak.orig	2023-05-30 17:50:57 UTC
+++ 3rdparty/lzma/CPP/7zip/var_gcc.mak
@@ -6,7 +6,7 @@ IS_ARM64=
 CROSS_COMPILE=
 MY_ARCH=
 USE_ASM=
-CC=$(CROSS_COMPILE)gcc
-CXX=$(CROSS_COMPILE)g++
+CC=$(CC)
+CXX=$(CXX)
 
 # -march=armv8-a+crc+crypto
