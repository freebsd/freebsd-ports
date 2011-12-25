diff --git a/trx2edips.c b/trx2edips.c
index f8d068d..224bc12 100644
--- trx2edips.c
+++ trx2edips.c
@@ -6,6 +6,8 @@
 #include <errno.h>
 #include <unistd.h>
 
+#include "freebsd.h"
+
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define STORE32_LE(X)		bswap_32(X)
 #define LOAD32_LE(X)		bswap_32(X)
