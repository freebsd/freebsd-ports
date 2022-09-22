--- vendor/alac/codec/EndianPortable.c.orig	2022-09-22 17:41:40 UTC
+++ vendor/alac/codec/EndianPortable.c
@@ -37,6 +37,8 @@
 #define TARGET_RT_LITTLE_ENDIAN 1
 #elif defined(__aarch64__)
 #define TARGET_RT_LITTLE_ENDIAN 1
+#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
+#define TARGET_RT_LITTLE_ENDIAN 1
 #elif defined (TARGET_OS_WIN32)
 #define TARGET_RT_LITTLE_ENDIAN 1
 #endif
