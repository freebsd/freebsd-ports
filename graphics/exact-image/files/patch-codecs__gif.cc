--- codecs/gif.cc.orig	2010-03-03 21:04:44 UTC
+++ codecs/gif.cc
@@ -22,6 +22,24 @@
 
 #include <iostream>
 
+#if GIFLIB_MAJOR >= 5
+void ExactImagePrintGifError(int ErrorCode)
+#else
+void ExactImagePrintGifError(void)
+#endif
+{
+#if GIFLIB_MAJOR >= 5
+  char *Err = GifErrorString(ErrorCode);
+#else
+  char *Err = GifErrorString();
+  int ErrorCode = GifError();
+#endif
+  if (Err != NULL)
+    std::cerr << "\nGIF-LIB error: " << Err << std::endl;
+  else
+    std::cerr << "\nGIF-LIB undefined error " << ErrorCode << "." << std::endl;
+}
+
 /* The way Interlaced image should. */
 static const int InterlacedOffset[] = { 0, 4, 2, 1 };
 
@@ -60,9 +78,13 @@ int GIFCodec::readImage (std::istream* s
   ColorMapObject *ColorMap = NULL;
   int ExtCode;
   
+#if GIFLIB_MAJOR >= 5
+  if ((GifFile = DGifOpen (stream, &GIFInputFunc, NULL)) == NULL)
+#else
   if ((GifFile = DGifOpen (stream, &GIFInputFunc)) == NULL)
+#endif
     {
-      PrintGifError();
+      std::cerr << "\nGIF-LIB error: can't open GIF file" << std::endl;
       return false;
     }
   
@@ -74,7 +96,11 @@ int GIFCodec::readImage (std::istream* s
   /* Scan the content of the GIF file and load the image(s) in: */
   do {
     if (DGifGetRecordType(GifFile, &RecordType) == GIF_ERROR) {
-      PrintGifError();
+#if GIFLIB_MAJOR >= 5
+      ExactImagePrintGifError(GifFile->Error);
+#else
+      ExactImagePrintGifError();
+#endif
       return false;
     }
     
@@ -83,7 +109,11 @@ int GIFCodec::readImage (std::istream* s
     switch (RecordType) {
     case IMAGE_DESC_RECORD_TYPE:
       if (DGifGetImageDesc(GifFile) == GIF_ERROR) {
-	PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	ExactImagePrintGifError(GifFile->Error);
+#else
+	ExactImagePrintGifError();
+#endif
 	return false;
       }
       
@@ -104,7 +134,11 @@ int GIFCodec::readImage (std::istream* s
 	       j += InterlacedJumps[i]) {
 	    if (DGifGetLine(GifFile, &image.getRawData()[j*image.stride()+Col],
 			    Width) == GIF_ERROR) {
-	      PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	      ExactImagePrintGifError(GifFile->Error);
+#else
+	      ExactImagePrintGifError();
+#endif
 	      return false;
 	    }
 	  }
@@ -113,7 +147,11 @@ int GIFCodec::readImage (std::istream* s
 	for (int i = 0; i < Height; ++i) {
 	  if (DGifGetLine(GifFile, &image.getRawData()[Row++ * image.stride()+Col],
 			  Width) == GIF_ERROR) {
-	    PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	    ExactImagePrintGifError(GifFile->Error);
+#else
+	    ExactImagePrintGifError();
+#endif
 	    return false;
 	  }
 	}
@@ -122,12 +160,20 @@ int GIFCodec::readImage (std::istream* s
     case EXTENSION_RECORD_TYPE:
       /* Skip any extension blocks in file: */
       if (DGifGetExtension(GifFile, &ExtCode, &Extension) == GIF_ERROR) {
-	PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	ExactImagePrintGifError(GifFile->Error);
+#else
+	ExactImagePrintGifError();
+#endif
 	return false;
       }
       while (Extension != NULL) {
 	if (DGifGetExtensionNext(GifFile, &Extension) == GIF_ERROR) {
-	  PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	  ExactImagePrintGifError(GifFile->Error);
+#else
+	  ExactImagePrintGifError();
+#endif
 	  return false;
 	}
       }
@@ -166,7 +212,11 @@ bool GIFCodec::writeImage (std::ostream*
   GifFileType* GifFile;
   GifByteType* Ptr;
   
+#if GIFLIB_MAJOR >= 5
+  if ((GifFile = EGifOpen (stream, &GIFOutputFunc, NULL)) == NULL)
+#else
   if ((GifFile = EGifOpen (stream, &GIFOutputFunc)) == NULL)
+#endif
     {
       std::cerr << "Error preparing GIF file for writing." << std::endl;
       return false;
@@ -175,7 +225,11 @@ bool GIFCodec::writeImage (std::ostream*
   int ColorMapSize = 256;
   
   // later use our own colormap generation
+#if GIFLIB_MAJOR >= 5
+  ColorMapObject* OutputColorMap = GifMakeMapObject(ColorMapSize, NULL);
+#else
   ColorMapObject* OutputColorMap = MakeMapObject(ColorMapSize, NULL);
+#endif
   if (!OutputColorMap)
     return false;
   
@@ -203,7 +257,11 @@ bool GIFCodec::writeImage (std::ostream*
   }
    
   
+#if GIFLIB_MAJOR >= 5
+  if (GifQuantizeBuffer(image.w, image.h, &ColorMapSize,
+#else
   if (QuantizeBuffer(image.w, image.h, &ColorMapSize,
+#endif
 		     RedBuffer, GreenBuffer, BlueBuffer,
 		     OutputBuffer, OutputColorMap->Colors) == GIF_ERROR) {
     return false;
@@ -215,7 +273,7 @@ bool GIFCodec::writeImage (std::ostream*
   if (EGifPutScreenDesc(GifFile, image.w, image.h,
 			ColorMapSize, 0, OutputColorMap) == GIF_ERROR ||
       EGifPutImageDesc(GifFile, 0, 0, image.w, image.h,
-		       FALSE, NULL) == GIF_ERROR)
+		       false, NULL) == GIF_ERROR)
     {
       std::cerr << "Error writing GIF header." << std::endl;
       return false;
@@ -232,7 +290,7 @@ bool GIFCodec::writeImage (std::ostream*
   }
   free (OutputBuffer);
 
-  delete (RedBuffer); delete (GreenBuffer); delete (BlueBuffer);
+  delete[] RedBuffer; delete[] GreenBuffer; delete[] BlueBuffer;
 
   EGifCloseFile(GifFile);
   return true;
