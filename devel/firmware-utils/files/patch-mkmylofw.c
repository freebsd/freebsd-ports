diff --git a/mkmylofw.c b/mkmylofw.c
index 585a9f9..927a0f7 100644
--- mkmylofw.c
+++ mkmylofw.c
@@ -28,7 +28,9 @@
 #include <stdarg.h>
 #include <errno.h>
 #include <sys/stat.h>
-#include <endian.h>     /* for __BYTE_ORDER */
+#include <sys/endian.h>     /* for __BYTE_ORDER */
+
+#include "freebsd.h"
 
 #if defined(__CYGWIN__)
 #  include <byteswap.h>
