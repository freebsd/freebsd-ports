--- src/gfx/ggidrv.cc.orig	Sun Jan 25 03:56:28 2004
+++ src/gfx/ggidrv.cc	Sun Jan 25 03:57:34 2004
@@ -383,7 +383,7 @@
 }
 /**************************************************************************/
 int set_palette(PALETTE p) {
-	struct ggi_color pal[256];
+	ggi_color pal[256];
 	int i;
 
         for(i=0;i<256;i++) {
@@ -398,7 +398,7 @@
 };
 /**************************************************************************/
 void get_palette(PALETTE p) {
-	struct ggi_color pal[256];
+	ggi_color pal[256];
 	int i;
 
         ggiGetPalette(screen->vis, 0, 1 << 8, pal);
@@ -715,7 +715,7 @@
 }
 /**************************************************************************/
 int set_color(int i, RGB *rgb) {
-	struct ggi_color Color;
+	ggi_color Color;
 
         Color.r = rgb->r << 10;
         Color.g = rgb->g << 10;
