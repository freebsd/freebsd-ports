--- include/ogl_defs.h.orig	2008-10-09 09:34:21.000000000 +0400
+++ include/ogl_defs.h	2009-02-26 23:25:34.000000000 +0300
@@ -220,7 +220,7 @@
 
 #else //GL_VERSION_20
 
-#  ifdef __macosx__
+#  if defined(__macosx__) || defined(__FreeBSD__)
 #    define glCreateShaderObject   glCreateShaderObjectARB
 #    define glShaderSource         glShaderSourceARB
 #    define glCompileShader        glCompileShaderARB
