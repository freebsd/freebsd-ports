--- utils/audiotool.cpp.orig	2015-11-03 08:30:29 UTC
+++ utils/audiotool.cpp
@@ -20,7 +20,10 @@
 #include <ccaudio2.h>
 #include <ccaudio2-config.h>
 #ifdef  HAVE_ENDIAN_H
-#include <endian.h>
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
 #endif
 
 #if !defined(__BIG_ENDIAN)
