--- ref_gl/qgl.h.orig	Sat Jul 21 11:52:11 2007
+++ ref_gl/qgl.h	Sat Jul 21 11:54:16 2007
@@ -393,6 +393,7 @@
 extern	void ( APIENTRY * qglClientActiveTextureARB)( GLenum );
 
 extern	void ( APIENTRY * qglMultiTexCoord3fvARB)( GLenum, GLfloat * );
+#if 0
 // jitwater - fragment programs (pixel shaders)
 typedef void (APIENTRY * PFNGLPROGRAMSTRINGARBPROC) (GLenum target, GLenum format, GLsizei len, const GLvoid *string);
 typedef void (APIENTRY * PFNGLBINDPROGRAMARBPROC) (GLenum target, GLuint program);
@@ -412,6 +413,7 @@
 typedef void (APIENTRY * PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) (GLenum target, GLuint index, GLfloat *params);
 typedef void (APIENTRY * PFNGLGETPROGRAMIVARBPROC) (GLenum target, GLenum pname, GLint *params);
 typedef void (APIENTRY * PFNGLGETPROGRAMSTRINGARBPROC) (GLenum target, GLenum pname, GLvoid *string);
+#endif
 
 #ifdef _WIN32
 
