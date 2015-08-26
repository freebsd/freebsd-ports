--- mkzcfw.c.orig	2011-12-22 14:21:03 UTC
+++ mkzcfw.c
@@ -18,6 +18,7 @@
 #include <errno.h>
 #include <sys/stat.h>
 
+#include "freebsd.h"
 #include "cyg_crc.h"
 
 #if (__BYTE_ORDER == __BIG_ENDIAN)
