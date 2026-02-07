--- ./src/vdrivers/vd_xwin.c.orig	Wed Apr  2 16:36:46 2003
+++ ./src/vdrivers/vd_xwin.c	Sat Jul  1 16:06:12 2006
@@ -18,6 +18,7 @@
  **
  **/
 
+#define	_UNISTD_H_
 #include "libgrx.h"
 #include "libxwin.h"
 #include "grdriver.h"
