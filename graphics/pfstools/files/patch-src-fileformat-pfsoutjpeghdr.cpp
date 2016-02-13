--- src/fileformat/pfsoutjpeghdr.cpp.orig	2005-11-04 08:54:27 UTC
+++ src/fileformat/pfsoutjpeghdr.cpp
@@ -69,8 +69,7 @@ void writeHDRJPEGGray( FILE *fh, int wid
    jhinf.correction = correction;
    jpeg_stdio_dest(&jhinf.cinfo, fh);
    
-   image = (JHSAMPLE *)malloc(width * height *
-          sizeof(JHSAMPLE)*3);
+   image = new JHSAMPLE[width * height * 3];
    
    for(int i=0;i<width * height;i++)
    {
@@ -91,7 +90,7 @@ void writeHDRJPEGGray( FILE *fh, int wid
    // Or, assign jhinf.tmi 8-bit grayscale values in scanline order
    jpeghdr_do_compress(&jhinf);
    jpeghdr_destroy_compress(&jhinf);
-   fclose(fh);
+   delete[] image;
 }
 
 void writeHDRJPEGRGB( FILE *fh, int width, int height,
@@ -111,8 +110,7 @@ void writeHDRJPEGRGB( FILE *fh, int widt
    jhinf.beta = beta;
    jpeg_stdio_dest(&jhinf.cinfo, fh);
    
-   image = (JHSAMPLE *)malloc(width * height *
-          sizeof(JHSAMPLE)*3);
+   image = new JHSAMPLE[width * height * 3];
    
    for(int i=0;i<width * height;i++)
    {
@@ -135,7 +133,7 @@ void writeHDRJPEGRGB( FILE *fh, int widt
    jpeghdr_do_compress(&jhinf);
    jpeghdr_destroy_compress(&jhinf);
 
-   free( image );
+   delete[] image;
 }
 
 void writeFrames( int argc, char* argv[] )
