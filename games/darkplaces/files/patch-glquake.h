--- glquake.h.orig	2011-10-22 00:02:41.000000000 +0400
+++ glquake.h	2011-10-21 23:16:37.000000000 +0400
@@ -758,9 +758,11 @@
 
 // GL 2.0 shader objects
 #ifndef GL_PROGRAM_OBJECT
+#ifndef __glext_h_
 // 1-byte character string
 typedef char GLchar;
 #endif
+#endif
 extern void (GLAPIENTRY *qglDeleteShader)(GLuint obj);
 extern void (GLAPIENTRY *qglDeleteProgram)(GLuint obj);
 //extern GLuint (GLAPIENTRY *qglGetHandle)(GLenum pname);
