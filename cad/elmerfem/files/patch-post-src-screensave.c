--- post/src/screensave.c.orig	2016-07-15 11:02:59 UTC
+++ post/src/screensave.c
@@ -32,6 +32,7 @@
 #include <GL/glu.h>
 
 
+#define	USE_INTERP_RESULT
 #include "tcl.h"
 
 #if !(defined(WIN32) || defined(win32))
