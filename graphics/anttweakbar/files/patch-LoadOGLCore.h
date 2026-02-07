- typedefs cause error: typedef redefinition with different types ('ptrdiff_t' (aka 'int') vs 'khronos_intptr_t' (aka 'long'))

--- LoadOGLCore.h.orig	2021-03-28 08:30:01 UTC
+++ LoadOGLCore.h
@@ -152,9 +152,11 @@ ANT_GL_CORE_DECL(void, glPointParameterfv, (GLenum pna
 ANT_GL_CORE_DECL(void, glPointParameteri, (GLenum pname, GLint param))
 ANT_GL_CORE_DECL(void, glPointParameteriv, (GLenum pname, const GLint *params))
 // GL 1.5
+#if !defined(__FreeBSD__)
 #ifndef ANT_OSX
     typedef ptrdiff_t GLintptr;
     typedef ptrdiff_t GLsizeiptr;
+#endif
 #endif
 ANT_GL_CORE_DECL(void, glGenQueries, (GLsizei n, GLuint *ids))
 ANT_GL_CORE_DECL(void, glDeleteQueries, (GLsizei n, const GLuint *ids))
