--- src/oss.cpp.orig	2011-02-21 11:44:54.000000000 +0000
+++ src/oss.cpp	2011-02-21 11:45:19.000000000 +0000
@@ -20,6 +20,13 @@
 #include <config.h>
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
 
