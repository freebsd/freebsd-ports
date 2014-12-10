--- lib/gif_lib.h.orig	2012-05-06 22:55:48.000000000 +0200
+++ lib/gif_lib.h	2012-06-03 12:12:23.000000000 +0200
@@ -180,6 +180,15 @@
 #define D_GIF_ERR_IMAGE_DEFECT   112
 #define D_GIF_ERR_EOF_TOO_SOON   113
 
+/******************************************************************************
+ * O.K., here are the routines from GIF_LIB file QUANTIZE.C.              
+******************************************************************************/
+int QuantizeBuffer(unsigned int Width, unsigned int Height,
+                   int *ColorMapSize, GifByteType * RedInput,
+                   GifByteType * GreenInput, GifByteType * BlueInput,
+                   GifByteType * OutputBuffer,
+                   GifColorType * OutputColorMap);
+
 /* These are legacy.  You probably do not want to call them directly */
 int DGifGetScreenDesc(GifFileType * GifFile);
 int DGifGetRecordType(GifFileType * GifFile, GifRecordType * GifType);
