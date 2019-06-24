--- src/curl.c.orig	2019-06-19 09:02:26 UTC
+++ src/curl.c
@@ -24,6 +24,8 @@
 #define BSWAP_32 OSSwapInt32
 #elif (defined(__OpenBSD__))
 #define BSWAP_32(x) swap32(x)
+#elif (defined(__FreeBSD__))
+#include <sys/endian.h>
 #elif (defined(__GLIBC__))
 #include <byteswap.h>
 #define BSWAP_32(x) bswap_32(x)
@@ -146,7 +148,7 @@ static size_t rcurl_read(void *target, size_t sz, size
 static int rcurl_fgetc(Rconnection con) {
   int x = 0;
 #ifdef WORDS_BIGENDIAN
-  return rcurl_read(&x, 1, 1, con) ? BSWAP_32(x) : R_EOF;
+  return rcurl_read(&x, 1, 1, con) ? bswap32(x) : R_EOF;
 #else
   return rcurl_read(&x, 1, 1, con) ? x : R_EOF;
 #endif
