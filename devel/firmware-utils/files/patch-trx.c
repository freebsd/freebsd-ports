--- trx.c.orig	2011-12-22 14:21:03 UTC
+++ trx.c
@@ -51,6 +51,8 @@
 #include <errno.h>
 #include <unistd.h>
 
+#include "freebsd.h"
+
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define STORE32_LE(X)		bswap_32(X)
 #define LOAD32_LE(X)		bswap_32(X)
