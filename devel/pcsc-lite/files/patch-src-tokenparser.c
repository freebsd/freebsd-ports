--- src/tokenparser.c.orig	Fri Sep 26 15:53:22 2003
+++ src/tokenparser.c	Fri Sep 26 15:53:40 2003
@@ -20,7 +20,10 @@
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <osreldate.h>
+#if __FreeBSD_version >= 500028
 #include <stdint.h> /* May break IA64 test-noansi-r */
+#endif
 
 /* end standard C headers. */
 
