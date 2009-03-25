--- ./lib/appUtil/appUtilX11.c.orig	2009-02-18 17:02:41.000000000 +0900
+++ ./lib/appUtil/appUtilX11.c	2009-03-24 18:54:18.000000000 +0900
@@ -26,6 +26,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include <libgen.h>
+#endif
 
 #include "vmware.h"
 #include "str.h"
