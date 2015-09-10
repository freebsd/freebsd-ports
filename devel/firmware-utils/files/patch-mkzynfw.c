--- mkzynfw.c.orig	2011-12-22 14:21:03 UTC
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
