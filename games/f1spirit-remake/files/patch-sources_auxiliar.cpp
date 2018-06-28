--- sources/auxiliar.cpp.orig	2018-06-28 15:42:12 UTC
+++ sources/auxiliar.cpp
@@ -88,7 +88,7 @@ SDL_Surface *load_maskedimage(char *imag
 	mask=IMG_Load(name);
 
     if (tmp==0 ||
-		mask==0) return false;
+		mask==0) return NULL;
 
 	res=SDL_DisplayFormatAlpha(tmp);
 
