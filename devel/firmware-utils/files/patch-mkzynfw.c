diff --git a/mkzynfw.c b/mkzynfw.c
index 36c176f..22d8bd3 100644
--- mkzynfw.c
+++ mkzynfw.c
@@ -23,11 +23,12 @@
 #include <stdarg.h>
 #include <errno.h>
 #include <sys/stat.h>
-#include <endian.h>	/* for __BYTE_ORDER */
+#include <sys/endian.h>	/* for __BYTE_ORDER */
 #if defined(__CYGWIN__)
 #  include <byteswap.h>
 #endif
 
+#include "freebsd.h"
 #include "zynos.h"
 
 #if (__BYTE_ORDER == __LITTLE_ENDIAN)
