--- source/games/dkong.c.orig	Mon Jan 17 10:04:09 2005
+++ source/games/dkong.c	Mon Jan 17 10:33:14 2005
@@ -479,7 +479,7 @@

 static void draw_emudx() {
   UINT8 code, color;
-  SCROLL_REGS;
+  SCROLL_REGS
   UINT8 *map,*gfx;
   int offs;
   int curlev = 0;
@@ -517,8 +517,8 @@
     gfx = gfx_ram;

   if( check_layer_enabled(layer_id_data[0])) {
-    MAKE_SCROLL_n_16(512,512,1,0, 0);
-    START_SCROLL_16(BORDER,BORDER,512,512);
+    MAKE_SCROLL_n_16(512,512,1,0, 0)
+    START_SCROLL_16(BORDER,BORDER,512,512)

     int sy = y-16*2;
     if (sy < 0 || sy > 224*2+BORDER)
@@ -716,20 +716,21 @@
   /* As always for the color prom, great thanks go to mame for their decoding work */
   for (i=0; i<256; i++) {
     UINT8 bit0, bit1, bit2;
+    int r,g,b;
     /* red component */
     bit0 = (color_prom[256] >> 1) & 1;
     bit1 = (color_prom[256] >> 2) & 1;
     bit2 = (color_prom[256] >> 3) & 1;
-    int r = 7 - (bit0 | (bit1<<1) | (bit2 << 2));
+    r = 7 - (bit0 | (bit1<<1) | (bit2 << 2));
     /* green component */
     bit0 = (color_prom[0] >> 2) & 1;
     bit1 = (color_prom[0] >> 3) & 1;
     bit2 = (color_prom[256] >> 0) & 1;
-    int g = 7 - (bit0 | (bit1<<1) | (bit2 << 2));
+    g = 7 - (bit0 | (bit1<<1) | (bit2 << 2));
     /* blue component */
     bit0 = (color_prom[0] >> 0) & 1;
     bit1 = (color_prom[0] >> 1) & 1;
-    int b = 7 - ((bit0<<1) | (bit1 << 2));
+    b = 7 - ((bit0<<1) | (bit1 << 2));
     RAM_PAL[i] = (b) | (g<<3) | (r<<6);
     color_prom++;
   }
@@ -800,9 +801,9 @@

 static void draw_dkong() {
   UINT8 code, color;
-  SCROLL_REGS;
+  SCROLL_REGS
   UINT8 *map,*gfx;
-  int offs;
+  int offs,sy;

   if (*gfx_bank) {
     gfx = gfx_ram + 0x100;
@@ -813,7 +814,7 @@
     MAKE_SCROLL_n_8(256,256,1,0, 0);
     START_SCROLL_8(BORDER,BORDER,256,256);

-    int sy = y-16;
+    sy = y-16;
     if (sy < 0 || sy > 224+BORDER)
       continue;
     code = gfx[tile_index];
