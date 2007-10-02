--- src/mp4_tag.c.orig	2007-10-02 22:05:09.000000000 +0400
+++ src/mp4_tag.c	2007-10-02 22:05:22.000000000 +0400
@@ -185,7 +185,7 @@
      * Picture *
      ***********/
     // There is only one picture!
-    if ( MP4GetMetadataCoverArt( mp4file, &coverArt, &coverSize ) )
+    if ( MP4GetMetadataCoverArt( mp4file, &coverArt, &coverSize, 0 ) )
     {
         Picture *pic = Picture_Allocate();
         pic->size = coverSize;
