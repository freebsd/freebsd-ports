--- src/utils.c.orig	Sat Sep 24 23:02:41 2005
+++ src/utils.c	Sun Oct  2 23:53:53 2005
@@ -239,7 +239,6 @@
 }
 #endif
 
-#define DEBUG_IMG_LOAD
 static SDL_Surface *load_image_prefix(const char *prefix, const char *name)
 {
 	SDL_Surface *surface = NULL;
