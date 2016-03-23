--- src/fileformat/pfsoutimgmagick.cpp.orig	2011-03-15 08:47:24 UTC
+++ src/fileformat/pfsoutimgmagick.cpp
@@ -190,6 +190,7 @@ void writeFrames( int argc, char* argv[]
         if( alpha != NULL )
           imgBuffer[i++] = (unsigned short)(maxValue-clamp((*alpha)(pix),0.f,1.f)*maxValue);
       }
+      Magick::InitializeMagick(*argv);
       Magick::Image imImage( frame->getWidth(), frame->getHeight(),
         (alpha == NULL ? "RGB" : "RGBA"), Magick::ShortPixel, imgBuffer );
       imImage.quality( quality );
