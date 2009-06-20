--- ./tilesdl.cc.orig	2009-06-19 13:55:52.000000000 +0200
+++ ./tilesdl.cc	2009-06-19 13:56:17.000000000 +0200
@@ -234,7 +234,7 @@
 #ifdef WIN32TILES
     const char *icon_name = "dat/tiles/stone_soup_icon-win32.png";
 #else
-    const char *icon_name = "dat/tiles/stone_soup_icon-32x32.png";
+    const char *icon_name = "%%DATADIR%%/dat/tiles/stone_soup_icon-32x32.png";
 #endif
     SDL_Surface *icon = IMG_Load(icon_name);
     if (!icon)
