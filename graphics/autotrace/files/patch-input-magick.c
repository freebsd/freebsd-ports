--- input-magick.c.orig	2008-12-02 22:58:14.000000000 +0100
+++ input-magick.c	2008-12-02 22:58:31.000000000 +0100
@@ -83,7 +83,7 @@
 
   for(j=0,runcount=0,point=0;j<image->rows;j++)
     for(i=0;i<image->columns;i++) {
-      p=GetOnePixel(image,i,j);
+      GetOnePixel(image,i,j, pixel);
       AT_BITMAP_BITS(bitmap)[point++]=pixel->red; /* if gray: red=green=blue */
       if(np==3) {
         AT_BITMAP_BITS(bitmap)[point++]=pixel->green;
