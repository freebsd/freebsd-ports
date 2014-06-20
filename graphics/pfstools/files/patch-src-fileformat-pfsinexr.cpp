--- src/fileformat/pfsinexr.cpp.orig	2008-01-01 13:01:21.000000000 +0000
+++ src/fileformat/pfsinexr.cpp	2014-02-20 19:04:01.546588828 +0000
@@ -234,7 +234,7 @@
     }
     
     file.setFrameBuffer( frameBuffer );
-    file.readPixels( dw.min.y, dw.max.y );
+    file.readPixels( dtw.min.y, dtw.max.y );
 
     VERBOSE_STR << "reading file (linear) '" << ff.fileName << "'" << std::endl;
     
