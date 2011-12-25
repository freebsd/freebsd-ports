diff --git a/mkcasfw.c b/mkcasfw.c
index 626e77d..fe9f122 100644
--- mkcasfw.c
+++ mkcasfw.c
@@ -19,11 +19,13 @@
 #include <stdarg.h>
 #include <errno.h>
 #include <sys/stat.h>
-#include <endian.h>     /* for __BYTE_ORDER */
+#include <sys/endian.h>     /* for __BYTE_ORDER */
 #if defined(__CYGWIN__)
 #  include <byteswap.h>
 #endif
 
+#include "freebsd.h"
+
 #if (__BYTE_ORDER == __LITTLE_ENDIAN)
 #  define HOST_TO_LE16(x)	(x)
 #  define HOST_TO_LE32(x)	(x)
