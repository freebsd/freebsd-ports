--- source/bezel.c.orig	Thu Nov 17 18:24:59 2005
+++ source/bezel.c	Thu Nov 17 18:49:28 2005
@@ -18,7 +18,7 @@
 #define __USE_ISOC99 1
 #include <math.h>
 
-#ifdef RAINE_DOS
+#if defined(RAINE_DOS) || __FreeBSD_version < 500300
 // djgpp seems to have specificities for rounding...
 // why on earth non one implements cleanly such basic function ???
 #define round rint
@@ -296,6 +296,7 @@
     int w = bezel_width, h = bezel_height;
     int multw =1, multh = 1;
     int xoff2,yoff2,destx,desty,xxx,yyy;
+    BITMAP *scaled_bezel;
 
     if (!w || !h) {
 	    // if wants_switch_res = 0, then the bezel is not initalised when arriving here...
@@ -316,7 +317,7 @@
 
     w *= multw; h *= multh;
     print_debug("bezel: create bitmap %dx%d\n",w,h);
-    BITMAP *scaled_bezel = create_bitmap_ex(bitmap_color_depth(bezel_bitmap),w,h);
+    scaled_bezel = create_bitmap_ex(bitmap_color_depth(bezel_bitmap),w,h);
     stretch_blit(bezel_bitmap,scaled_bezel,0,0,bezel_bitmap->w-1,bezel_bitmap->h-1,0,0,w,h);
 
     if (rotate_screen == 3 || rotate_screen == 1) { // 270
