--- codecs/jpeg.cc.orig	2009-07-02 18:34:41.000000000 -0400
+++ codecs/jpeg.cc	2009-07-02 18:43:42.000000000 -0400
@@ -683,7 +683,7 @@
      * We need to clean up the JPEG object, close the input file, and return.
      */
     jpeg_destroy_decompress (cinfo);
-    free (cinfo);
+    delete[] cinfo;
     return false;
   }
   
