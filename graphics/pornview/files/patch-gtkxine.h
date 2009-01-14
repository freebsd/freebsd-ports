--- src/support/widgets/gtkxine.h.orig	Sat Nov 23 22:56:41 2002
+++ src/support/widgets/gtkxine.h	Sat Dec  7 15:09:28 2002
@@ -12,6 +12,7 @@
 
 #ifdef ENABLE_XINE
 
+#include <pthread.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/extensions/XShm.h>
