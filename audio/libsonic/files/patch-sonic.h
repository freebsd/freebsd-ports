--- sonic.h.orig	2018-10-15 14:25:10 UTC
+++ sonic.h
@@ -189,8 +189,6 @@ struct sonicBitmapStruct {
   int numCols;
 };
 
-typedef struct sonicBitmapStruct* sonicBitmap;
-
 /* Enable coomputation of a spectrogram on the fly. */
 void sonicComputeSpectrogram(sonicStream stream);
 
