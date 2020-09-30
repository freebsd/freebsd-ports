--- src/gl_intern.h.orig	2008-10-11 12:10:39 UTC
+++ src/gl_intern.h
@@ -83,6 +83,6 @@ int gld_GetTexDimension(int value);
 void gld_SetTexturePalette(GLenum target);
 void gld_Precache(void);
 
-PFNGLCOLORTABLEEXTPROC gld_ColorTableEXT;
+extern PFNGLCOLORTABLEEXTPROC gld_ColorTableEXT;
 
 #endif // _GL_INTERN_H
