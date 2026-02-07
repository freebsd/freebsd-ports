--- ref_gl/gl_local.h.orig	Mon Apr 23 17:46:04 2007
+++ ref_gl/gl_local.h	Mon Apr 23 18:59:06 2007
@@ -138,6 +138,11 @@
 #define VID_ERR_FULLSCREEN_FAILED	4
 #define VID_ERR_INVALID_MODE		8
 
+typedef int rserr_t;
+
+#define rserr_ok			VID_ERR_NONE
+#define rserr_invalid_mode		VID_ERR_INVALID_MODE
+
 #include "gl_model.h"
 
 void GL_BeginRendering (int *x, int *y, int *width, int *height);
