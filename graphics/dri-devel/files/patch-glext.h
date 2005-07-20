--- include/GL/glext.h.orig	Wed Jul 20 00:37:30 2005
+++ include/GL/glext.h	Wed Jul 20 00:37:39 2005
@@ -4192,7 +4192,7 @@
 #ifndef GL_EXT_texture3D
 #define GL_EXT_texture3D 1
 #ifdef GL_GLEXT_PROTOTYPES
-GLAPI void APIENTRY glTexImage3DEXT (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
+GLAPI void APIENTRY glTexImage3DEXT (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
 GLAPI void APIENTRY glTexSubImage3DEXT (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
 #endif /* GL_GLEXT_PROTOTYPES */
 typedef void (APIENTRYP PFNGLTEXIMAGE3DEXTPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
