--- codecs/jpeg.cc.orig	2009-06-14 08:19:28.000000000 -0400
+++ codecs/jpeg.cc	2010-01-16 21:51:34.000000000 -0500
@@ -683,7 +683,7 @@
      * We need to clean up the JPEG object, close the input file, and return.
      */
     jpeg_destroy_decompress (cinfo);
-    free (cinfo);
+    delete cinfo;
     return false;
   }
   
