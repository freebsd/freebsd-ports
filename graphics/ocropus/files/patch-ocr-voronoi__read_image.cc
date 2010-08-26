--- ocr-voronoi/read_image.cc.orig	2009-05-31 22:18:41.000000000 +0200
+++ ocr-voronoi/read_image.cc	2010-08-26 21:23:06.000000000 +0200
@@ -102,7 +102,7 @@
     */
     int tiff_p(char* fname)
     {
-        TIFFHeader hdr;
+        TIFFHeaderClassic hdr;
         int fd;
 
         if((fd=open(fname, O_RDONLY|O_BINARY,0))<0){
@@ -119,7 +119,7 @@
            hdr.tiff_magic != TIFF_LITTLEENDIAN){
             return(NO);
         }
-        if(hdr.tiff_version != TIFF_VERSION &&
+        if(hdr.tiff_version != TIFF_VERSION_CLASSIC &&
            hdr.tiff_version != II_TIFF_VER){
             return(NO);
         }
