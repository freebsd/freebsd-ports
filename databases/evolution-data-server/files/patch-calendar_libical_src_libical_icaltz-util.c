--- calendar/libical/src/libical/icaltz-util.c.orig	2008-12-22 04:49:23.000000000 -0500
+++ calendar/libical/src/libical/icaltz-util.c	2009-01-12 22:33:53.000000000 -0500
@@ -23,6 +23,15 @@
 #include <string.h>
 #if defined(sun) && defined(__SVR4)
 #include <sys/byteorder.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define __BYTE_ORDER            _BYTE_ORDER
+#define __LITTLE_ENDIAN         _LITTLE_ENDIAN
+#define __BIG_ENDIAN            _BIG_ENDIAN
+
+#define bswap_16                bswap16
+#define bswap_32                bswap32
+#define bswap_64                bswap64
 #elif defined(_WIN32)
 #define BIG_ENDIAN 'B'
 #define LITTLE_ENDIAN 'l'
