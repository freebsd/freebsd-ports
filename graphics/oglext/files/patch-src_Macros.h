--- src/Macros.h.orig	Thu Aug 19 23:19:51 2004
+++ src/Macros.h	Thu Aug 19 23:20:28 2004
@@ -19,6 +19,7 @@
 
 #if !defined(_WIN32) && (!defined(__APPLE__) || !defined(__GNUC__)) && !defined(__MACOSX__)
 
+	#define GLX_GLXEXT_PROTOTYPES
 	#include <GL/glx.h>
 
 #endif
