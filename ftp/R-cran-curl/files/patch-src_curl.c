--- src/curl.c.orig	2019-09-11 10:18:36 UTC
+++ src/curl.c
@@ -19,11 +19,13 @@
 #ifdef WORDS_BIGENDIAN
 #if (defined(__sun) && defined(__SVR4))
 #include <sys/byteorder.h>
-#elif (defined(__APPLE__) && defined(__ppc__) || defined(__ppc64__))
+#elif defined(__APPLE__) && (defined(__ppc__) || defined(__ppc64__))
 #include <libkern/OSByteOrder.h>
 #define BSWAP_32 OSSwapInt32
 #elif (defined(__OpenBSD__))
 #define BSWAP_32(x) swap32(x)
+#elif (defined(__FreeBSD__))
+#include <sys/endian.h>
 #elif (defined(__GLIBC__))
 #include <byteswap.h>
 #define BSWAP_32(x) bswap_32(x)
@@ -148,7 +150,7 @@ static size_t rcurl_read(void *target, size_t sz, size
 static int rcurl_fgetc(Rconnection con) {
   int x = 0;
 #ifdef WORDS_BIGENDIAN
-  return rcurl_read(&x, 1, 1, con) ? BSWAP_32(x) : R_EOF;
+  return rcurl_read(&x, 1, 1, con) ? bswap32(x) : R_EOF;
 #else
   return rcurl_read(&x, 1, 1, con) ? x : R_EOF;
 #endif
