--- source/games/frogger.c.orig	Sat Sep 17 10:35:38 2005
+++ source/games/frogger.c	Thu Nov 17 16:52:10 2005
@@ -438,7 +438,7 @@
 
 static void draw_emudx() {
   UINT8 code,color;
-  SCROLL_REGS;
+  SCROLL_REGS
   UINT8 *map,*solid;
   int coul1, coul2;
 
@@ -796,7 +796,7 @@
      rotated you call it either col or row scroll ! */
 
   UINT8 code, color;
-  SCROLL_REGS;
+  SCROLL_REGS
   UINT8 *map,*solid;
   int coul1, coul2;
   UINT8 *gfx = load_region[REGION_GFX1];
@@ -868,8 +868,8 @@
   }
 
   if( check_layer_enabled(layer_id_data[1])) {
-    solid = gfx_solid[1];
     int offs;
+    solid = gfx_solid[1];
     for (offs = 0x20 - 4;offs >= 0;offs -= 4) {
       UINT8 sx,sy,color;
       int flipx,flipy,code;
