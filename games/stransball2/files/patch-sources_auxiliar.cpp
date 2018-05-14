--- sources/auxiliar.cpp.orig	2018-05-14 19:20:42 UTC
+++ sources/auxiliar.cpp
@@ -48,7 +48,7 @@ SDL_Surface *load_maskedimage(char *imag
 	mask=IMG_Load(name);
 
     if (tmp==0 ||
-		mask==0) return false;
+		mask==0) return NULL;
 
 	res=SDL_DisplayFormatAlpha(tmp);
 
