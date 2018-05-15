--- src/VBox/GuestHost/OpenGL/include/chromium.h.orig	2018-05-09 16:38:12 UTC
+++ src/VBox/GuestHost/OpenGL/include/chromium.h
@@ -63,7 +63,7 @@
 #include <GL/gl.h>
 /* Quick fix so as not to update the version of glext.h we provide. */
 #ifdef GL_GLEXT_PROTOTYPES
-# if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS)
+# if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS)
 GLAPI void APIENTRY glBindFramebuffer (GLenum, GLuint);
 GLAPI void APIENTRY glBlitFramebuffer (GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
 GLAPI GLenum APIENTRY glCheckFramebufferStatus (GLenum);
