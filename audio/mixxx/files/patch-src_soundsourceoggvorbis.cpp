--- src/soundsourceoggvorbis.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/soundsourceoggvorbis.cpp
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
