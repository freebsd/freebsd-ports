--- source/games/frogger.c.orig	Mon Jan 17 10:37:51 2005
+++ source/games/frogger.c	Mon Jan 17 10:40:26 2005
@@ -437,7 +437,7 @@

 static void draw_emudx() {
   UINT8 code,color;
-  SCROLL_REGS;
+  SCROLL_REGS
   UINT8 *map,*solid;
   int coul1, coul2;

@@ -794,7 +794,7 @@
      rotated you call it either col or row scroll ! */

   UINT8 code, color;
-  SCROLL_REGS;
+  SCROLL_REGS
   UINT8 *map,*solid;
   int coul1, coul2;

@@ -865,8 +865,8 @@
   }

   if( check_layer_enabled(layer_id_data[1])) {
-    solid = GFX_SOLID[1];
     int offs;
+    solid = GFX_SOLID[1];
     for (offs = 0x20 - 4;offs >= 0;offs -= 4) {
       UINT8 sx,sy,color;
       int flipx,flipy,code;
