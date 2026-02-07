diff --git a/freeglut/freeglut/src/fg_gl2.c b/freeglut/freeglut/src/fg_gl2.c
index 38b0acbb..54b4285b 100644
--- src/fg_gl2.c
+++ src/fg_gl2.c
@@ -27,6 +27,20 @@
 #include "fg_internal.h"
 #include "fg_gl2.h"
 
+#ifndef GL_ES_VERSION_2_0
+/* GLES2 has the corresponding entry points built-in, and these fgh-prefixed
+ * names are defined in fg_gl2.h header to reference them, for any other case,
+ * define them as function pointers here.
+ */
+FGH_PFNGLGENBUFFERSPROC fghGenBuffers;
+FGH_PFNGLDELETEBUFFERSPROC fghDeleteBuffers;
+FGH_PFNGLBINDBUFFERPROC fghBindBuffer;
+FGH_PFNGLBUFFERDATAPROC fghBufferData;
+FGH_PFNGLENABLEVERTEXATTRIBARRAYPROC fghEnableVertexAttribArray;
+FGH_PFNGLDISABLEVERTEXATTRIBARRAYPROC fghDisableVertexAttribArray;
+FGH_PFNGLVERTEXATTRIBPOINTERPROC fghVertexAttribPointer;
+#endif
+
 void FGAPIENTRY glutSetVertexAttribCoord3(GLint attrib) {
   if (fgStructure.CurrentWindow != NULL)
     fgStructure.CurrentWindow->Window.attribute_v_coord = attrib;
diff --git a/freeglut/freeglut/src/fg_gl2.h b/freeglut/freeglut/src/fg_gl2.h
index ab8ba5c7..fb3d4676 100644
--- src/fg_gl2.h
+++ src/fg_gl2.h
@@ -67,13 +67,13 @@ typedef void (APIENTRY *FGH_PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
 typedef void (APIENTRY *FGH_PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint);
 typedef void (APIENTRY *FGH_PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
 
-FGH_PFNGLGENBUFFERSPROC fghGenBuffers;
-FGH_PFNGLDELETEBUFFERSPROC fghDeleteBuffers;
-FGH_PFNGLBINDBUFFERPROC fghBindBuffer;
-FGH_PFNGLBUFFERDATAPROC fghBufferData;
-FGH_PFNGLENABLEVERTEXATTRIBARRAYPROC fghEnableVertexAttribArray;
-FGH_PFNGLDISABLEVERTEXATTRIBARRAYPROC fghDisableVertexAttribArray;
-FGH_PFNGLVERTEXATTRIBPOINTERPROC fghVertexAttribPointer;
+extern FGH_PFNGLGENBUFFERSPROC fghGenBuffers;
+extern FGH_PFNGLDELETEBUFFERSPROC fghDeleteBuffers;
+extern FGH_PFNGLBINDBUFFERPROC fghBindBuffer;
+extern FGH_PFNGLBUFFERDATAPROC fghBufferData;
+extern FGH_PFNGLENABLEVERTEXATTRIBARRAYPROC fghEnableVertexAttribArray;
+extern FGH_PFNGLDISABLEVERTEXATTRIBARRAYPROC fghDisableVertexAttribArray;
+extern FGH_PFNGLVERTEXATTRIBPOINTERPROC fghVertexAttribPointer;
 
 #    endif
 
