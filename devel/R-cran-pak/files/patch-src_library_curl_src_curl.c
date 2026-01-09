--- src/library/curl/src/curl.c.orig	2026-01-09 10:51:35 UTC
+++ src/library/curl/src/curl.c
@@ -33,6 +33,9 @@
 #define BSWAP_32(x) bswap_32(x)
 #elif (defined(_AIX))
 #define BSWAP_32(x) __builtin_bswap32(x)
+#elif (defined(__FreeBSD__))
+#include <sys/endian.h>
+#define BSWAP_32(x) bswap32(x)
 #endif
 #endif
 
