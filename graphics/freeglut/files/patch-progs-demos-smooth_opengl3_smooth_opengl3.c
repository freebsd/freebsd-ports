--- progs/demos/smooth_opengl3/smooth_opengl3.c.orig	2012-01-04 14:38:43.000000000 +0100
+++ progs/demos/smooth_opengl3/smooth_opengl3.c	2012-01-04 14:39:10.000000000 +0100
@@ -98,6 +98,7 @@
 #define APIENTRY
 #endif
 
+#ifndef GL_VERSION_1_5
 typedef void (APIENTRY *PFNGLGENBUFFERSPROC) (GLsizei n, GLuint *buffers);
 typedef void (APIENTRY *PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
 typedef void (APIENTRY *PFNGLBUFFERDATAPROC) (GLenum target, ourGLsizeiptr size, const GLvoid *data, GLenum usage);
@@ -117,6 +118,7 @@
 typedef void (APIENTRY *PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
 typedef GLint (APIENTRY *PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const ourGLchar *name);
 typedef void (APIENTRY *PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
+#endif
 
 PFNGLGENBUFFERSPROC gl_GenBuffers;
 PFNGLBINDBUFFERPROC gl_BindBuffer;
