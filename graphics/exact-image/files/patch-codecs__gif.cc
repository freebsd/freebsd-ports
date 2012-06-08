--- codecs/gif.cc.orig	2010-03-03 16:04:44.000000000 -0500
+++ codecs/gif.cc	2012-06-08 14:47:50.000000000 -0400
@@ -22,6 +22,17 @@
 
 #include <iostream>
 
+void ExactImagePrintGifError(void)
+{
+  char *Err = GifErrorString();
+  if (Err != NULL)
+    std::cerr << "\nGIF-LIB error: " << Err << std::endl;
+  else
+    std::cerr << "\nGIF-LIB undefined error " << GifError() << "." << std::endl;
+}
+
+#define PrintGifError ExactImagePrintGifError
+
 /* The way Interlaced image should. */
 static const int InterlacedOffset[] = { 0, 4, 2, 1 };
 
@@ -232,7 +243,7 @@
   }
   free (OutputBuffer);
 
-  delete (RedBuffer); delete (GreenBuffer); delete (BlueBuffer);
+  delete[] RedBuffer; delete[] GreenBuffer; delete[] BlueBuffer;
 
   EGifCloseFile(GifFile);
   return true;
