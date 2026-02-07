--- gl_util.c.orig	2011-07-07 08:39:22.000000000 -0500
+++ gl_util.c	2011-10-12 22:09:31.520959086 -0500
@@ -756,6 +756,12 @@ int gl_component_count(GLenum format, GL
 
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
