--- src/friends.cpp.orig	2011-02-21 11:15:41.000000000 +0000
+++ src/friends.cpp	2011-02-21 11:30:59.000000000 +0000
@@ -22,6 +22,13 @@
 #include <ctype.h>
 #ifdef  HAVE_ENDIAN_H
 #include <endian.h>
+#else
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __LITTLE_ENDIAN (_BYTE_ORDER == _LITTLE_ENDIAN)
+#define __BIG_ENDIAN    (_BYTE_ORDER == _BIG_ENDIAN)
+#define __BYTE_ORDER _BYTE_ORDER
+#endif
 #endif
 #include <ucommon/export.h>
 #include <ccaudio2.h>
