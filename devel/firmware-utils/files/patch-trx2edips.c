--- trx2edips.c.orig	2011-12-22 14:21:03 UTC
+++ trx2edips.c
@@ -6,6 +6,8 @@
 #include <errno.h>
 #include <unistd.h>
 
+#include "freebsd.h"
+
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define STORE32_LE(X)		bswap_32(X)
 #define LOAD32_LE(X)		bswap_32(X)
