--- src/fileformat/pfsinexr.cpp.orig	2008-01-01 13:01:21 UTC
+++ src/fileformat/pfsinexr.cpp
@@ -234,7 +234,7 @@ void readFrames( int argc, char* argv[] 
     }
     
     file.setFrameBuffer( frameBuffer );
-    file.readPixels( dw.min.y, dw.max.y );
+    file.readPixels( dtw.min.y, dtw.max.y );
 
     VERBOSE_STR << "reading file (linear) '" << ff.fileName << "'" << std::endl;
     
