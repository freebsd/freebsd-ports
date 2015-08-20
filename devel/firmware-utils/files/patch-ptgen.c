--- ptgen.c.orig	2011-12-22 14:21:03 UTC
+++ ptgen.c
@@ -29,6 +29,8 @@
 #include <ctype.h>
 #include <fcntl.h>
 
+#include "freebsd.h"
+
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define cpu_to_le16(x) bswap_16(x)
 #elif __BYTE_ORDER == __LITTLE_ENDIAN
