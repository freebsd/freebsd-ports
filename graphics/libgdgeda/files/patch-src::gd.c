--- src/gd.c.orig	Mon Oct  2 21:44:49 2000
+++ src/gd.c	Tue Nov 20 22:15:17 2001
@@ -1,6 +1,6 @@
-#ifndef _OSD_POSIX	/* _OSD_POSIX defines *alloc() in stdlib.h */
-#include <malloc.h>
-#endif /*_OSD_POSIX*/
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 #include <stdio.h>
 #include <math.h>
 #include <string.h>
