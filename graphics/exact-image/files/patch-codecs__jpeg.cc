--- codecs/jpeg.cc.orig	2017-08-08 14:31:16 UTC
+++ codecs/jpeg.cc
@@ -901,7 +901,7 @@ bool JPEGCodec::readMeta (std::istream* stream, Image&
     // If we get here, the JPEG code has signaled an error.
     // We need to clean up the JPEG object, close the input file, and return.
     jpeg_destroy_decompress (cinfo);
-    free (cinfo);
+    delete cinfo;
     return false;
   }
   
