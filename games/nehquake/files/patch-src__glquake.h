--- ./src/glquake.h.orig	Tue Sep 27 19:06:49 2005
+++ ./src/glquake.h	Tue May 16 17:36:22 2006
@@ -275,7 +275,6 @@
 #define    TEXTURE1_SGIS gl_Texture1
 
 #ifndef _WIN32
-#define APIENTRY /* */
 #endif
 
 typedef void (APIENTRY *lpMTexFUNC) (GLenum, GLfloat, GLfloat);
