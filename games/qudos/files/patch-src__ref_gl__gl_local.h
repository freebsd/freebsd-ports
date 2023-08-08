--- src/ref_gl/gl_local.h.orig	2006-06-10 10:22:27 UTC
+++ src/ref_gl/gl_local.h
@@ -30,6 +30,7 @@
 #include <GL/glext.h>
 
 #include <png.h>
+#include <zlib.h>
 #include <jpeglib.h>
 
 #include "../client/ref.h"
@@ -480,12 +481,6 @@ int		Draw_GetPalette(void);
 void		GL_ResampleTexture(unsigned *in, int inwidth, int inheight, unsigned *out, int outwidth, int outheight);
 
 struct image_s *R_RegisterSkin(char *name);
-
-void		LoadPCX   (char *filename, byte ** pic, byte ** palette, int *width, int *height);
-void		LoadTGA   (char *filename, byte ** pic, int *width, int *height);
-void		LoadJPG   (char *filename, byte ** pic, int *width, int *height);
-void		LoadPNG   (char *filename, byte ** pic, int *width, int *height);
-
 
 image_t        *GL_LoadPic(char *name, byte * pic, int width, int height, imagetype_t type, int bits);
 image_t        *GL_FindImage(char *name, imagetype_t type);
