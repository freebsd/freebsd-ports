--- codecs/gif.cc.orig	2015-03-28 15:35:58 UTC
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
+  const char *Err = GifErrorString(ErrorCode);
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
 
@@ -60,9 +78,13 @@ int GIFCodec::readImage (std::istream* stream, Image& 
   ColorMapObject *ColorMap = 0;
   int GifError, ExtCode;
   
+#if GIFLIB_MAJOR >= 5
   if ((GifFile = DGifOpen (stream, &GIFInputFunc, &GifError)) == 0)
+#else
+  if ((GifFile = DGifOpen (stream, &GIFInputFunc)) == 0)
+#endif
     {
-      //PrintGifError();
+      std::cerr << "\nGIF-LIB error: can't open GIF file" << std::endl;
       return false;
     }
   
@@ -74,7 +96,11 @@ int GIFCodec::readImage (std::istream* stream, Image& 
   /* Scan the content of the GIF file and load the image(s) in: */
   do {
     if (DGifGetRecordType(GifFile, &RecordType) == GIF_ERROR) {
-      //PrintGifError();
+#if GIFLIB_MAJOR >= 5
+      ExactImagePrintGifError(GifFile->Error);
+#else
+      ExactImagePrintGifError();
+#endif
       return false;
     }
     
@@ -83,7 +109,11 @@ int GIFCodec::readImage (std::istream* stream, Image& 
     switch (RecordType) {
     case IMAGE_DESC_RECORD_TYPE:
       if (DGifGetImageDesc(GifFile) == GIF_ERROR) {
-	//PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	ExactImagePrintGifError(GifFile->Error);
+#else
+	ExactImagePrintGifError();
+#endif
 	return false;
       }
       
@@ -104,7 +134,11 @@ int GIFCodec::readImage (std::istream* stream, Image& 
 	       j += InterlacedJumps[i]) {
 	    if (DGifGetLine(GifFile, &image.getRawData()[j*image.stride()+Col],
 			    Width) == GIF_ERROR) {
-	      //PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	      ExactImagePrintGifError(GifFile->Error);
+#else
+	      ExactImagePrintGifError();
+#endif
 	      return false;
 	    }
 	  }
@@ -113,7 +147,11 @@ int GIFCodec::readImage (std::istream* stream, Image& 
 	for (int i = 0; i < Height; ++i) {
 	  if (DGifGetLine(GifFile, &image.getRawData()[Row++ * image.stride()+Col],
 			  Width) == GIF_ERROR) {
-	    //PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	    ExactImagePrintGifError(GifFile->Error);
+#else
+	    ExactImagePrintGifError();
+#endif
 	    return false;
 	  }
 	}
@@ -122,12 +160,20 @@ int GIFCodec::readImage (std::istream* stream, Image& 
     case EXTENSION_RECORD_TYPE:
       /* Skip any extension blocks in file: */
       if (DGifGetExtension(GifFile, &ExtCode, &Extension) == GIF_ERROR) {
-	//PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	ExactImagePrintGifError(GifFile->Error);
+#else
+	ExactImagePrintGifError();
+#endif
 	return false;
       }
       while (Extension != 0) {
 	if (DGifGetExtensionNext(GifFile, &Extension) == GIF_ERROR) {
-	  //PrintGifError();
+#if GIFLIB_MAJOR >= 5
+	  ExactImagePrintGifError(GifFile->Error);
+#else
+	  ExactImagePrintGifError();
+#endif
 	  return false;
 	}
       }
@@ -155,7 +201,11 @@ int GIFCodec::readImage (std::istream* stream, Image& 
   // convert colormap to our 16bit "TIFF"format
   colorspace_de_palette (image, ColorMap->ColorCount, rmap, gmap, bmap);
   
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
   EGifCloseFile(GifFile, &GifError);
+#else
+  EGifCloseFile(GifFile);
+#endif
 
   return true;
 }
@@ -167,7 +217,11 @@ bool GIFCodec::writeImage (std::ostream* stream, Image
   GifByteType* Ptr;
   int GifError;
   
+#if GIFLIB_MAJOR >= 5
   if ((GifFile = EGifOpen(stream, &GIFOutputFunc, &GifError)) == 0)
+#else
+  if ((GifFile = EGifOpen(stream, &GIFOutputFunc)) == 0)
+#endif
     {
       std::cerr << "Error preparing GIF file for writing." << std::endl;
       return false;
@@ -176,7 +230,11 @@ bool GIFCodec::writeImage (std::ostream* stream, Image
   int ColorMapSize = 256;
   
   // later use our own colormap generation
+#if GIFLIB_MAJOR >= 5
   ColorMapObject* OutputColorMap = GifMakeMapObject(ColorMapSize, 0);
+#else
+  ColorMapObject* OutputColorMap = MakeMapObject(ColorMapSize, 0);
+#endif
   if (!OutputColorMap)
     return false;
   
@@ -204,7 +262,11 @@ bool GIFCodec::writeImage (std::ostream* stream, Image
   }
    
   
+#if GIFLIB_MAJOR >= 5
   if (GifQuantizeBuffer(image.w, image.h, &ColorMapSize,
+#else
+  if (QuantizeBuffer(image.w, image.h, &ColorMapSize,
+#endif
 		     RedBuffer, GreenBuffer, BlueBuffer,
 		     OutputBuffer, OutputColorMap->Colors) == GIF_ERROR) {
     return false;
@@ -235,7 +297,11 @@ bool GIFCodec::writeImage (std::ostream* stream, Image
 
   delete[] RedBuffer; delete[] GreenBuffer; delete[] BlueBuffer;
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
   EGifCloseFile(GifFile, &GifError);
+#else
+  EGifCloseFile(GifFile);
+#endif
   return true;
 }
 
