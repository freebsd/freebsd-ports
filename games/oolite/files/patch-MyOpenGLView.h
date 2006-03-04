--- MyOpenGLView.h.orig	Thu Feb 23 20:26:20 2006
+++ MyOpenGLView.h	Thu Feb 23 20:26:30 2006
@@ -39,7 +39,7 @@
 #import "OOOpenGL.h"
 
 #ifdef GNUSTEP
-#include <SDL/SDL.h>
+#include <SDL.h>
 #endif
 
 #define MAX_CLEAR_DEPTH		100000000.0
