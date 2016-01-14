--- src/audiofile.cpp.orig	2015-10-23 22:39:25 UTC
+++ src/audiofile.cpp
@@ -20,7 +20,10 @@
 #include <ucommon/ucommon.h>
 #include <ccaudio2-config.h>
 #ifdef  HAVE_ENDIAN_H
-#include <endian.h>
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
 #endif
 #include <ucommon/export.h>
 #include <ccaudio2.h>
