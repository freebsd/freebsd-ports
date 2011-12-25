diff --git a/ptgen.c b/ptgen.c
index d94aabb..4733311 100644
--- ptgen.c
+++ ptgen.c
@@ -29,6 +29,8 @@
 #include <ctype.h>
 #include <fcntl.h>
 
+#include "freebsd.h"
+
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define cpu_to_le16(x) bswap_16(x)
 #elif __BYTE_ORDER == __LITTLE_ENDIAN
