--- src/curl.c.orig	2022-10-17 18:09:53 UTC
+++ src/curl.c
@@ -19,7 +19,7 @@
 #ifdef WORDS_BIGENDIAN
 #if (defined(__sun) && defined(__SVR4))
 #include <sys/byteorder.h>
-#elif (defined(__APPLE__) && defined(__ppc__) || defined(__ppc64__))
+#elif defined(__APPLE__) && (defined(__ppc__) || defined(__ppc64__))
 #include <libkern/OSByteOrder.h>
 #define BSWAP_32 OSSwapInt32
 #elif (defined(__OpenBSD__))
@@ -27,6 +27,9 @@
 #elif (defined(__NetBSD__))
 #include <sys/types.h>
 #include <machine/bswap.h>
+#define BSWAP_32(x) bswap32(x)
+#elif (defined(__FreeBSD__))
+#include <sys/endian.h>
 #define BSWAP_32(x) bswap32(x)
 #elif (defined(__GLIBC__))
 #include <byteswap.h>
