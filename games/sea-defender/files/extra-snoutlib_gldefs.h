--- snoutlib/gldefs.h.orig	2013-09-28 23:51:46.789551906 +0200
+++ snoutlib/gldefs.h	2013-09-28 23:52:40.941548852 +0200
@@ -94,7 +94,7 @@
 typedef GLboolean (GLFUNCDEF PFNGLISPROGRAMPROC) (GLuint);
 typedef GLboolean (GLFUNCDEF PFNGLISSHADERPROC) (GLuint);
 typedef void (GLFUNCDEF PFNGLLINKPROGRAMPROC) (GLuint);
-typedef void (GLFUNCDEF PFNGLSHADERSOURCEPROC) (GLuint, GLsizei, const GLchar* *, const GLint *);
+typedef void (GLFUNCDEF PFNGLSHADERSOURCEPROC) (GLuint, GLsizei, const GLchar* const *, const GLint *);
 typedef void (GLFUNCDEF PFNGLUSEPROGRAMPROC) (GLuint);
 typedef void (GLFUNCDEF PFNGLUNIFORM1FPROC) (GLint, GLfloat);
 typedef void (GLFUNCDEF PFNGLUNIFORM2FPROC) (GLint, GLfloat, GLfloat);
