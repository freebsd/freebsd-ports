--- dcraw.cc.orig	2018-06-23 21:54:05 UTC
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
@@ -8946,7 +8949,7 @@ void CLASS identify()
     parse_fuji (get4());
     if (thumb_offset > 120) {
       fseek (ifp, 120, SEEK_SET);
-      is_raw += (i = get4()) && 1;
+      is_raw += (i = get4()) & 1;
       if (is_raw == 2 && shot_select)
 	parse_fuji (i);
     }
@@ -10192,7 +10195,7 @@ void CLASS tiff_head (struct tiff_hdr *t
   strncpy (th->desc, desc, 512);
   strncpy (th->make, make, 64);
   strncpy (th->model, model, 64);
-  strcpy (th->soft, "dcraw v"DCRAW_VERSION);
+  strcpy (th->soft, " dcraw v " DCRAW_VERSION);
   t = localtime (&timestamp);
   sprintf (th->date, "%04d:%02d:%02d %02d:%02d:%02d",
       t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
