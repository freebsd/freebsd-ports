--- gl_util.c.orig	Wed Jun 20 09:03:02 2001
+++ gl_util.c	Tue Dec 14 18:41:08 2004
@@ -1,5 +1,8 @@
 
 #include "gl_util.h"
+#if defined(HAVE_GLEXT_H) && !defined(GL_BLEND_EQUATION_EXT)
+#include <GL/glext.h>
+#endif
 
 int gl_texparameter_count(GLenum pname)
 {
@@ -708,6 +711,12 @@
 
 /* 18 */
 #ifdef GL_EXT_cmyka
+# ifndef GL_CMYK
+#  define GL_CMYK GL_CMYK_EXT
+# endif
+# ifndef GL_CMYKA
+#  define GL_CMYKA GL_CMYKA_EXT
+# endif
 		case GL_CMYK:
 			n = 4; break;
 		case GL_CMYKA:
