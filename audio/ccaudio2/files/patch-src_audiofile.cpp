--- src/audiofile.cpp.orig	2011-02-21 11:11:41.000000000 +0000
+++ src/audiofile.cpp	2011-02-21 11:16:03.000000000 +0000
@@ -20,6 +20,12 @@
 #include <config.h>
 #ifdef  HAVE_ENDIAN_H
 #include <endian.h>
+#else
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#endif
 #endif
 #include <ucommon/export.h>
 #include <ccaudio2.h>
