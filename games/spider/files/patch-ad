--- globals.h.orig	1991-09-28 17:46:20.000000000 +0000
+++ globals.h	2011-07-01 03:25:27.000000000 +0000
@@ -96,6 +96,10 @@
 Bool	can_get_help_files();
 #endif
 
+#ifndef __FreeBSD__
 extern char	*malloc();
 extern char	*calloc();
 extern char	*realloc();
+#else
+#include <stdlib.h>
+#endif
