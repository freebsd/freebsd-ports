--- Sources/GL/GLX/displaycard_glx.cpp.orig	Thu Jan 22 14:15:47 2004
+++ Sources/GL/GLX/displaycard_glx.cpp	Thu Jan 22 14:26:58 2004
@@ -14,6 +14,9 @@
 
 #ifdef USE_OPENGL
 
+#define GLX_GLXEXT_PROTOTYPES
+#include <GL/glx.h>
+
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/cursorfont.h>
