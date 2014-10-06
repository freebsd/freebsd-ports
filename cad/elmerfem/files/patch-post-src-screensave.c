--- post/src/screensave.c.orig	2014-09-09 20:47:35.000000000 -0500
+++ post/src/screensave.c	2014-09-09 20:50:39.000000000 -0500
@@ -32,6 +32,7 @@
 #include <GL/glu.h>
 
 
+#define	USE_INTERP_RESULT
 #include "tcl.h"
 
 #if !(defined(WIN32) || defined(win32))
