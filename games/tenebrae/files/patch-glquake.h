
$FreeBSD$

--- glquake.h.orig
+++ glquake.h
@@ -419,8 +419,8 @@
 void R_TranslatePlayerSkin (int playernum);
 void GL_Bind (int texnum);
 
-#ifndef _WIN32
-#define APIENTRY /* */
+#ifndef APIENTRY
+#define APIENTRY
 #endif
 
 #if !defined (__APPLE__) && !defined (MACOSX)
@@ -470,6 +470,9 @@
 // ARB_texture_compression defines
 #define GL_COMPRESSED_RGBA_ARB                0x84EE
 
+#ifndef GL_ATI_separate_stencil
+#define GL_ATI_separate_stencil 1
+
 #define GL_STENCIL_BACK_FUNC_ATI                    0x8800
 #define GL_STENCIL_BACK_FAIL_ATI                    0x8801
 #define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI         0x8802
@@ -478,6 +481,8 @@
 typedef void (APIENTRY *PFNGLSTENCILOPSEPARATEATIPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
 typedef void (APIENTRY *PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
 
+#endif
+
 extern PFNGLSTENCILOPSEPARATEATIPROC qglStencilOpSeparateATI;
 extern PFNGLSTENCILFUNCSEPARATEATIPROC qglStencilFuncSeparateATI;
 
@@ -1134,8 +1139,13 @@
 // <AWE> There are some diffs with the function parameters. wgl stuff not present with MacOS X. -DC- and SDL 
 #if defined (__APPLE__) || defined (MACOSX) || defined(SDL) || defined (__glx__)
 
+#ifndef GL_APPLE_vertex_array_range
+#define GL_APPLE_vertex_array_range 1
+
 typedef void (APIENTRY * PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC) (GLsizei length, const GLvoid *pointer);
 typedef void (APIENTRY * PFNGLVERTEXARRAYRANGEAPPLEPROC) (GLsizei size, const GLvoid *pointer);
+
+#endif
 
 extern PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC qglFlushVertexArrayRangeAPPLE;
 extern PFNGLVERTEXARRAYRANGEAPPLEPROC qglVertexArrayRangeAPPLE;
