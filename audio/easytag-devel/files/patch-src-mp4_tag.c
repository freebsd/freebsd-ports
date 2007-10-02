--- src/mp4_tag.c.orig	2007-10-02 22:37:42.000000000 +0400
+++ src/mp4_tag.c	2007-10-02 22:39:54.000000000 +0400
@@ -185,7 +185,7 @@
      * Picture *
      ***********/
     // There is only one picture!
-    if ( MP4GetMetadataCoverArt( mp4file, &coverArt, &coverSize ) )
+    if ( MP4GetMetadataCoverArt( mp4file, &coverArt, &coverSize, 0 ) )
     {
         Picture *pic = Picture_Allocate();
         pic->size = coverSize;
