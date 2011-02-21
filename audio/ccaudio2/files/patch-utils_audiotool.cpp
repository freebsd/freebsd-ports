--- utils/audiotool.cpp.orig	2011-02-21 11:30:44.000000000 +0000
+++ utils/audiotool.cpp	2011-02-21 11:30:58.000000000 +0000
@@ -20,6 +20,13 @@
 #include <config.h>
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
 
 #if defined(_MSWINDOWS_) && !defined(__BIG_ENDIAN)
