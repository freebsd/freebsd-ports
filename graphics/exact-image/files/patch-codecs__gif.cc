--- codecs/gif.cc.orig	2009-07-02 18:34:16.000000000 -0400
+++ codecs/gif.cc	2009-07-02 18:38:40.000000000 -0400
@@ -232,7 +232,7 @@
   }
   free (OutputBuffer);
 
-  delete (RedBuffer); delete (GreenBuffer); delete (BlueBuffer);
+  delete[] RedBuffer; delete[] GreenBuffer; delete[] BlueBuffer;
 
   EGifCloseFile(GifFile);
   return true;
