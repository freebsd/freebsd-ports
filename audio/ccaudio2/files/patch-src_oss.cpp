--- src/oss.cpp.orig	2015-11-03 08:30:29 UTC
+++ src/oss.cpp
@@ -31,7 +31,10 @@ int _oss_ccaudio_dummy = 0;
 #include <unistd.h>
 #include <sys/soundcard.h>
 #ifdef  HAVE_ENDIAN_H
-#include <endian.h>
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
 #endif
 
 #include <ucommon/export.h>
