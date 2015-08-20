--- mkcsysimg.c.orig	2011-12-22 14:21:03 UTC
+++ mkcsysimg.c
@@ -32,11 +32,13 @@
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
 #include "csysimg.h"
 
 #if (__BYTE_ORDER == __LITTLE_ENDIAN)
