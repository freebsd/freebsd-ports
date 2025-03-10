--- src/Render.h.orig	2018-11-03 03:51:57 UTC
+++ src/Render.h
@@ -1,14 +1,11 @@
 #ifndef RENDER_H
 #define RENDER_H
 
+#include <SDL_ttf.h>
+
 #include <memory>
 
 #include "ImageManager.h"
-
-// The forward declaration of TTF_Font is clunky like this
-// as it's forward declared like this in SDL_ttf.h
-struct _TTF_Font;
-typedef struct _TTF_Font TTF_Font;
 
 // Deleter functor for textures.
 struct TextureDeleter {
