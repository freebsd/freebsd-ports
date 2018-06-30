--- asyncpg/protocol/hton.h.orig	2018-06-06 00:51:22 UTC
+++ asyncpg/protocol/hton.h
@@ -2,25 +2,47 @@
 
 #if defined(__linux__) || defined(__CYGWIN__)
 #include <endian.h>
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
-#include <sys/endian.h>
-#elif defined(__DragonFly__)
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) \
+      || defined(__DragonFly__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
-#define __BYTE_ORDER BYTE_ORDER
-#define __BIG_ENDIAN BIG_ENDIAN
-#define __LITTLE_ENDIAN LITTLE_ENDIAN
 #elif defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
 /* Assume Windows is always LE.  There seems to be no reliable way
    to detect endianness there */
 #define __LITTLE_ENDIAN 1234
 #define __BIG_ENDIAN 4321
 #define __BYTE_ORDER __LITTLE_ENDIAN
-#else
-#error Cannot determine platform byte order.
 #endif
 
+#if defined(_BYTE_ORDER) && !defined(__BYTE_ORDER)
+#define __BYTE_ORDER _BYTE_ORDER
+#endif
+
+#if defined(BYTE_ORDER) && !defined(__BYTE_ORDER)
+#define __BYTE_ORDER BYTE_ORDER
+#endif
+
+#if defined(_LITTLE_ENDIAN) && !defined(__LITTLE_ENDIAN)
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
+
+#if defined(LITTLE_ENDIAN) && !defined(__LITTLE_ENDIAN)
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#endif
+
+#if defined(_BIG_ENDIAN) && !defined(__BIG_ENDIAN)
+#define __BIG_ENDIAN _BIG_ENDIAN
+#endif
+
+#if defined(BIG_ENDIAN) && !defined(__BIG_ENDIAN)
+#define __BIG_ENDIAN BIG_ENDIAN
+#endif
+
+#if !defined(__BYTE_ORDER) || !defined(__LITTLE_ENDIAN) \
+    || !defined(__BIG_ENDIAN)
+#error Cannot determine platform byte order.
+#endif
 
 #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
 
