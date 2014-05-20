--- src/oss.cpp.orig	2014-01-28 20:43:54.000000000 +0100
+++ src/oss.cpp	2014-05-20 10:23:04.000000000 +0200
@@ -20,6 +20,13 @@
 #include <ccaudio2-config.h>
 #include <math.h>
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
+#endif
+
 extern int _oss_ccaudio_dummy;
 int _oss_ccaudio_dummy = 0;
 
