--- mkedimaximg.c.orig	2011-12-22 14:21:03 UTC
+++ mkedimaximg.c
@@ -15,7 +15,9 @@
 #include <getopt.h>
 #include <errno.h>
 #include <sys/stat.h>
-#include <endian.h>	/* for __BYTE_ORDER */
+#include <sys/endian.h>	/* for __BYTE_ORDER */
+
+#include "freebsd.h"
 
 #if (__BYTE_ORDER == __LITTLE_ENDIAN)
 #  define HOST_TO_LE16(x)	(x)
