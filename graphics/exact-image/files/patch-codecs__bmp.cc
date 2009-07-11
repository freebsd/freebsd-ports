--- codecs/bmp.cc.orig	2009-07-02 17:37:58.000000000 -0400
+++ codecs/bmp.cc	2009-07-02 18:38:49.000000000 -0400
@@ -628,9 +628,9 @@
       
       colorspace_de_palette (image, clr_tbl_size, rmap, gmap, bmap);
       
-      delete (rmap);
-      delete (gmap);
-      delete (bmap);
+      delete[] rmap;
+      delete[] gmap;
+      delete[] bmap;
       
       free(clr_tbl);
       clr_tbl = NULL;
