--- utilsgl/GLee.h.orig	2010-10-17 01:09:51 UTC
+++ utilsgl/GLee.h
@@ -66,8 +66,8 @@
     #define GL_GLEXT_LEGACY
 	#include <OpenGL/gl.h>
 #else // GLX
-	#define __glext_h_  /* prevent glext.h from being included  */
 	#define __glxext_h_ /* prevent glxext.h from being included */
+	#define GL_GLEXT_PROTOTYPES
 	#define GLX_GLXEXT_PROTOTYPES
 	#include <GL/gl.h>
 	#include <GL/glx.h>
