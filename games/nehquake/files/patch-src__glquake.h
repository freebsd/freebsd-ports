--- src/glquake.h.orig	2005-09-27 22:06:49 UTC
+++ src/glquake.h
@@ -275,7 +275,6 @@ extern GLenum gl_Texture1;
 #define    TEXTURE1_SGIS gl_Texture1
 
 #ifndef _WIN32
-#define APIENTRY /* */
 #endif
 
 typedef void (APIENTRY *lpMTexFUNC) (GLenum, GLfloat, GLfloat);
@@ -289,4 +288,4 @@ void GL_DisableMultitexture(void);
 void GL_EnableMultitexture(void);
 void GL_LightMaps_f (void);
 
-extern   bspversion;
+extern int bspversion;
