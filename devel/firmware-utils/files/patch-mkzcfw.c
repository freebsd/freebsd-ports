diff --git a/mkzcfw.c b/mkzcfw.c
index 7674e70..c60fc6f 100644
--- mkzcfw.c
+++ mkzcfw.c
@@ -18,6 +18,7 @@
 #include <errno.h>
 #include <sys/stat.h>
 
+#include "freebsd.h"
 #include "cyg_crc.h"
 
 #if (__BYTE_ORDER == __BIG_ENDIAN)
