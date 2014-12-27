--- src/libimage/gif.c.orig	2006-03-25 22:50:51 UTC
+++ src/libimage/gif.c
@@ -28,6 +28,26 @@
   distribution. 
 */
 
+static void
+#if GIFLIB_MAJOR >= 5
+localPrintGifError(int ErrorCode)
+#else
+localPrintGifError(void)
+#endif
+{
+#if GIFLIB_MAJOR >= 5
+    char *Err = GifErrorString(ErrorCode);
+#else
+    char *Err = GifErrorString();
+    int ErrorCode = GifError();
+#endif
+
+    if (Err != NULL)
+        fprintf(stderr, "\nGIF-LIB error: %s.\n", Err);
+    else
+        fprintf(stderr, "\nGIF-LIB undefined error %d.\n", ErrorCode);
+}
+
 int
 read_gif(const char *filename, int *width, int *height, unsigned char **rgb)
 {
@@ -42,11 +62,15 @@ read_gif(const char *filename, int *widt
     int color_index;
     unsigned char *ptr = NULL;
 
+#if GIFLIB_MAJOR >= 5
+    infile = DGifOpenFileName(filename, NULL);
+#else
     infile = DGifOpenFileName(filename);
+#endif
 
     if (infile == NULL)
     {
-        PrintGifError();
+        fprintf(stderr, "Can't open GIF file %s\n", filename);
         return(0);
     }
 
@@ -54,7 +78,11 @@ read_gif(const char *filename, int *widt
     {
         if (DGifGetRecordType(infile, &record_type) == GIF_ERROR) 
         {
-            PrintGifError();
+#if GIFLIB_MAJOR >= 5
+            localPrintGifError(infile->Error);
+#else
+            localPrintGifError();
+#endif
             return(0);
         }
 
@@ -63,7 +91,11 @@ read_gif(const char *filename, int *widt
         case IMAGE_DESC_RECORD_TYPE:
             if (DGifGetImageDesc(infile) == GIF_ERROR)
             {
-                PrintGifError();
+#if GIFLIB_MAJOR >= 5
+                localPrintGifError(infile->Error);
+#else
+                localPrintGifError();
+#endif
                 return(0);
             }
 
@@ -107,14 +139,22 @@ read_gif(const char *filename, int *widt
             GifByteType *ext;
             if (DGifGetExtension(infile, &ext_code, &ext) == GIF_ERROR) 
             {
-                PrintGifError();
+#if GIFLIB_MAJOR >= 5
+                localPrintGifError(infile->Error);
+#else
+                localPrintGifError();
+#endif
                 return(0);
             }
             while (ext != NULL) 
             {
                 if (DGifGetExtensionNext(infile, &ext) == GIF_ERROR) 
                 {
-                    PrintGifError();
+#if GIFLIB_MAJOR >= 5
+                    localPrintGifError(infile->Error);
+#else
+                    localPrintGifError();
+#endif
                     return(0);
                 }
             }
@@ -178,7 +218,11 @@ write_gif(const char *filename, int widt
         return(0);
     }
 
+#if GIFLIB_MAJOR >= 5
+    colormap = GifMakeMapObject(colormap_size, NULL);
+#else
     colormap = MakeMapObject(colormap_size, NULL);
+#endif
 
     for (i = 0; i < width * height; i++)
     {
@@ -187,10 +231,15 @@ write_gif(const char *filename, int widt
         blue[i]  = (GifByteType) rgb[3*i+2];
     }
   
+#if GIFLIB_MAJOR >= 5
+    if (GifQuantizeBuffer(width, height, &colormap_size, red, green, blue,   
+                       buffer, colormap->Colors) == GIF_ERROR)
+#else
     if (QuantizeBuffer(width, height, &colormap_size, red, green, blue,   
                        buffer, colormap->Colors) == GIF_ERROR)
+#endif
     {
-        PrintGifError();
+        fprintf(stderr, "Can't quantize buffer\n");
         return(0);
     }
 
@@ -198,24 +247,36 @@ write_gif(const char *filename, int widt
     free(green);
     free(blue);
 
-    outfile = EGifOpenFileName((char *) filename, FALSE);
+#if GIFLIB_MAJOR >= 5
+    outfile = EGifOpenFileName((char *) filename, false, NULL);
+#else
+    outfile = EGifOpenFileName((char *) filename, false);
+#endif
     if (outfile == NULL)
     {
-        PrintGifError();
+        fprintf(stderr, "Can't open GIF file %s\n", filename);
         return(0);
     }
 
     if (EGifPutScreenDesc(outfile, width, height, colormap_size, 0, colormap)
         == GIF_ERROR)
     {
-        PrintGifError();
+#if GIFLIB_MAJOR >= 5
+        localPrintGifError(outfile->Error);
+#else
+        localPrintGifError();
+#endif
         return(0);
     }
 
-    if (EGifPutImageDesc(outfile, 0, 0, width, height, FALSE, NULL)
+    if (EGifPutImageDesc(outfile, 0, 0, width, height, false, NULL)
         == GIF_ERROR)
     {
-        PrintGifError();
+#if GIFLIB_MAJOR >= 5
+        localPrintGifError(outfile->Error);
+#else
+        localPrintGifError();
+#endif
         return(0);
     }
 
@@ -224,7 +285,11 @@ write_gif(const char *filename, int widt
     {
         if (EGifPutLine(outfile, ptr, width) == GIF_ERROR)
         {
-            PrintGifError();
+#if GIFLIB_MAJOR >= 5
+            localPrintGifError(outfile->Error);
+#else
+            localPrintGifError();
+#endif
             return(0);
         }
         ptr += width;
@@ -233,7 +298,7 @@ write_gif(const char *filename, int widt
     EGifSpew(outfile);
 
     if (EGifCloseFile(outfile) == GIF_ERROR) 
-        PrintGifError();
+        fprintf(stderr, "Can't close GIF file %s\n", filename);
 
     free(buffer);
 
