--- src/soundsourceoggvorbis.cpp.orig	2011-12-24 11:53:20.000000000 +0900
+++ src/soundsourceoggvorbis.cpp	2012-01-16 06:10:09.000000000 +0900
@@ -32,6 +32,15 @@
 #endif
 #endif
 
+#ifdef __BSD__
+#include <sys/endian.h>
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#define OV_ENDIAN_ARG 0
+#else
+#define OV_ENDIAN_ARG 1
+#endif
+#endif
+
 #ifdef __LINUX__
 #include <endian.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
