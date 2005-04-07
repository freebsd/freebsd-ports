$FreeBSD$

--- src/gagui.h.orig	Fri Mar 25 15:17:42 2005
+++ src/gagui.h	Fri Mar 25 15:18:16 2005
@@ -11,7 +11,7 @@
  */
 /* kk --- 020619 added List and Free_List --- kk */
 
-#include "libsx.h"
+#include "X11/libsx/libsx.h"
 
 int init_display(int argc, char **argv, void *data);
 int Custom_GUI( char *fname );
