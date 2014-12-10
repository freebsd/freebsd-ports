--- util/rgb2gif.c.orig	2012-05-16 22:31:35.000000000 +0200
+++ util/rgb2gif.c	2012-06-03 12:23:21.000000000 +0200
@@ -129,7 +129,7 @@
  *   This function returns GIF_OK if succesfull, GIF_ERROR otherwise.
  ******************************************************************************/
 static int
-QuantizeBuffer(unsigned int Width,
+GifQuantizeBuffer(unsigned int Width,
                unsigned int Height,
                int *ColorMapSize,
                GifByteType * RedInput,
@@ -428,7 +428,7 @@
 					    sizeof(GifByteType))) == NULL)
 	GIF_EXIT("Failed to allocate memory required, aborted.");
 
-    if (QuantizeBuffer(Width, Height, &ColorMapSize,
+    if (GifQuantizeBuffer(Width, Height, &ColorMapSize,
 		       RedBuffer, GreenBuffer, BlueBuffer,
 		       OutputBuffer, OutputColorMap->Colors) == GIF_ERROR)
 	QuitGifError(NULL);
