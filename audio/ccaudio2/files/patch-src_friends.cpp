--- src/friends.cpp.orig	2015-11-03 08:30:29 UTC
+++ src/friends.cpp
@@ -22,7 +22,10 @@
 #include <math.h>
 #include <ctype.h>
 #ifdef  HAVE_ENDIAN_H
-#include <endian.h>
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
 #endif
 #include <ucommon/export.h>
 #include <ccaudio2.h>
