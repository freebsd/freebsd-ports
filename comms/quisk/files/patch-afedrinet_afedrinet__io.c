--- afedrinet/afedrinet_io.c.orig	2019-05-23 04:31:28 UTC
+++ afedrinet/afedrinet_io.c
@@ -15,6 +15,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #endif
 
 #ifdef MS_WINDOWS
