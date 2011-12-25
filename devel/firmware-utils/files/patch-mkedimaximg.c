diff --git a/mkedimaximg.c b/mkedimaximg.c
index d8a017e..6d504e5 100644
--- mkedimaximg.c
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
