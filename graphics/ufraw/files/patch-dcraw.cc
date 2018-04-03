--- dcraw.cc.orig	2018-04-03 22:16:35 UTC
+++ dcraw.cc
@@ -2287,7 +2287,7 @@ void CLASS quicktake_100_load_raw()
 
 void CLASS kodak_radc_load_raw()
 {
-  static const char src[] = {
+  static const signed char src[] = {
     1,1, 2,3, 3,4, 4,2, 5,7, 6,5, 7,6, 7,8,
     1,0, 2,1, 3,3, 4,4, 5,2, 6,7, 7,6, 8,5, 8,8,
     2,1, 2,3, 3,0, 3,2, 3,4, 4,6, 5,5, 6,7, 6,8,
@@ -3017,7 +3017,10 @@ void CLASS smal_decode_segment (unsigned
       diff = diff ? -diff : 0x80;
     if (ftell(ifp) + 12 >= (int) seg[1][1])
       diff = 0;
-    raw_image[pix] = pred[pix & 1] += diff;
+    if(pix>=raw_width*raw_height)
+      derror();
+    else
+      raw_image[pix] = pred[pix & 1] += diff;
     if (!(pix & 1) && HOLE(pix / raw_width)) pix += 2;
   }
   maximum = 0xff;
