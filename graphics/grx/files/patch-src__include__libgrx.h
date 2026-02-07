--- src/include/libgrx.h.orig	Sun Mar  4 17:45:26 2001
+++ src/include/libgrx.h	Thu Aug  3 20:43:31 2006
@@ -132,6 +132,9 @@
 /*
 ** get system endian
 */
+#include <machine/endian.h>
+
+#if 0
 #if !defined(_BIG_ENDIAN) && !defined(_LITTLE_ENDIAN)
 #  if   defined(__TURBOC__) \
      || defined(__WATCOMC__) \
@@ -144,7 +147,9 @@
 #    include <sys/byteorder.h>
 #  endif
 #endif
+#endif
 
+#if 0
 #if defined(__BYTE_ORDER__) && !defined(BYTE_ORDER)
 #  define BYTE_ORDER    __BYTE_ORDER__
 #  define LITTLE_ENDIAN __LITTLE_ENDIAN__
@@ -163,6 +168,11 @@
 #ifndef BYTE_ORDER
 #error Unknown byte ordering !
 #endif
+#endif
+
+#define BYTE_ORDER    _BYTE_ORDER
+#define LITTLE_ENDIAN _LITTLE_ENDIAN
+#define BIG_ENDIAN    _BIG_ENDIAN
 
 #ifndef HARDWARE_BYTE_ORDER
 #define HARDWARE_BYTE_ORDER BYTE_ORDER
