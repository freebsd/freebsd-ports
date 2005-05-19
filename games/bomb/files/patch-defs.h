--- defs.h.orig	Tue Apr 18 03:37:05 2000
+++ defs.h	Wed May 18 23:19:55 2005
@@ -41,7 +41,7 @@
 #endif
 
 #if use_quicktime
-#include "quicktime.h"
+#include "lqt/quicktime.h"
 extern quicktime_t *qt_file;
 extern int use_jpeg;
 #endif
