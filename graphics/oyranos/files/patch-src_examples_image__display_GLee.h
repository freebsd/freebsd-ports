--- src/examples/image_display/GLee.h.orig	2016-12-09 10:36:53 UTC
+++ src/examples/image_display/GLee.h
@@ -63,6 +63,10 @@
 	#define __glext_h_  /* prevent glext.h from being included  */
 	#define __glxext_h_ /* prevent glxext.h from being included */
 	#define GLX_GLXEXT_PROTOTYPES
+	/* request entry point prototypes from the system headers */
+	#ifndef GL_GLEXT_PROTOTYPES
+	#define GL_GLEXT_PROTOTYPES
+	#endif
 	#include <GL/gl.h>
 	#include <GL/glx.h>
 #endif
