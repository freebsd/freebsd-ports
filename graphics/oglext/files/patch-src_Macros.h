--- src/Macros.h.orig	Mon Feb  2 19:23:57 2004
+++ src/Macros.h	Mon Feb  2 19:24:13 2004
@@ -18,7 +18,7 @@
 #define	_OGL_MACROS_H_
 
 #ifndef	_WIN32
-
+	#define GLX_GLXEXT_PROTOTYPES
 	#include <GL/glx.h>
 
 #endif
