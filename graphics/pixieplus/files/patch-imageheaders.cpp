--- app/imageheaders.cpp.orig	Fri Jun 13 00:47:07 2003
+++ app/imageheaders.cpp	Fri Jun 13 00:47:49 2003
@@ -90,7 +90,7 @@
         if(TIFFSetDirectory(t, thumbDir)){
             TIFFGetField(t, TIFFTAG_IMAGELENGTH, &height);
             img.create(minWidth, height, 32);
-            if(!TIFFReadRGBAImage(t, minWidth, height, (unsigned long*)
+            if(!TIFFReadRGBAImage(t, minWidth, height, (uint32*)
                                   img.bits(), 0))
                 img.reset();
             else{
