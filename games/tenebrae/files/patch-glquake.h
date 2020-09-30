--- glquake.h.orig	2020-09-30 11:25:10 UTC
+++ glquake.h
@@ -419,8 +419,8 @@ extern	const char *gl_extensions;
 void R_TranslatePlayerSkin (int playernum);
 void GL_Bind (int texnum);
 
-#ifndef _WIN32
-#define APIENTRY /* */
+#ifndef APIENTRY
+#define APIENTRY
 #endif
 
 #if !defined (__APPLE__) && !defined (MACOSX)
@@ -470,6 +470,9 @@ void GL_Bind (int texnum);
 // ARB_texture_compression defines
 #define GL_COMPRESSED_RGBA_ARB                0x84EE
 
+#ifndef GL_ATI_separate_stencil
+#define GL_ATI_separate_stencil 1
+
 #define GL_STENCIL_BACK_FUNC_ATI                    0x8800
 #define GL_STENCIL_BACK_FAIL_ATI                    0x8801
 #define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI         0x8802
@@ -478,6 +481,8 @@ void GL_Bind (int texnum);
 typedef void (APIENTRY *PFNGLSTENCILOPSEPARATEATIPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
 typedef void (APIENTRY *PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
 
+#endif
+
 extern PFNGLSTENCILOPSEPARATEATIPROC qglStencilOpSeparateATI;
 extern PFNGLSTENCILFUNCSEPARATEATIPROC qglStencilFuncSeparateATI;
 
@@ -1134,9 +1139,14 @@ extern PFNGLVERTEXATTRIBS4UBVNVPROC qglVertexAttribs4u
 // <AWE> There are some diffs with the function parameters. wgl stuff not present with MacOS X. -DC- and SDL 
 #if defined (__APPLE__) || defined (MACOSX) || defined(SDL) || defined (__glx__)
 
+#ifndef GL_APPLE_vertex_array_range
+#define GL_APPLE_vertex_array_range 1
+
 typedef void (APIENTRY * PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC) (GLsizei length, const GLvoid *pointer);
 typedef void (APIENTRY * PFNGLVERTEXARRAYRANGEAPPLEPROC) (GLsizei size, const GLvoid *pointer);
 
+#endif
+
 extern PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC qglFlushVertexArrayRangeAPPLE;
 extern PFNGLVERTEXARRAYRANGEAPPLEPROC qglVertexArrayRangeAPPLE;
 
@@ -1524,7 +1534,7 @@ extern mirrorplane_t mirrorplanes[NUM_MIRROR_PLANES];
 extern int mirror_contents;
 extern int newenvmap;
 
-msurface_t	*causticschain;
+extern msurface_t	*causticschain;
 extern int	caustics_textures[8];
 extern qboolean	busy_caustics;
 
