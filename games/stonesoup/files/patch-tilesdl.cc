--- ./tilesdl.cc.orig	2009-10-15 18:41:56.000000000 +0200
+++ ./tilesdl.cc	2009-10-15 18:42:16.000000000 +0200
@@ -249,7 +249,7 @@
             "dat/tiles/stone_soup_icon-32x32.png";
 #endif
 
-    SDL_Surface *icon = IMG_Load(datafile_path(icon_name).c_str());
+    SDL_Surface *icon = IMG_Load(datafile_path(icon_name, true, true).c_str());
     if (!icon)
     {
         printf("Failed to load icon: %s\n", SDL_GetError());
