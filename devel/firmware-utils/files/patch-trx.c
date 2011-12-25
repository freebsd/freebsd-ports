diff --git a/trx.c b/trx.c
index 8e95d98..765f83c 100644
--- trx.c
+++ trx.c
@@ -51,6 +51,8 @@
 #include <errno.h>
 #include <unistd.h>
 
+#include "freebsd.h"
+
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define STORE32_LE(X)		bswap_32(X)
 #define LOAD32_LE(X)		bswap_32(X)
