--- source/games/esd16.c.orig	Thu Nov 17 16:34:24 2005
+++ source/games/esd16.c	Thu Nov 17 16:34:48 2005
@@ -552,12 +552,13 @@
 }
 
 static void draw_multchmp() {
-  ClearPaletteMap();
   int x16,y16,zzz,zzzz;
   int zz;
   int x,y;
   UINT16 code;
   UINT8 *map;
+
+  ClearPaletteMap();
 
   // 1 layer is opaque 1024x512, 8x8 sprites
   if (check_layer_enabled(layer_id_data[1])) {
