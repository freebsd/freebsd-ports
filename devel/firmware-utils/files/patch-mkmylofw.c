--- mkmylofw.c.orig	2011-12-22 14:21:03 UTC
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
