--- codecs/gif.cc.orig	2017-07-21 14:19:01 UTC
+++ codecs/gif.cc
@@ -22,6 +22,312 @@
 
 #include <iostream>
 
+#define ABS(x) ((x) > 0 ? (x) : (-(x)))
+#define COLOR_ARRAY_SIZE 32768
+#define BITS_PER_PRIM_COLOR 5
+#define MAX_PRIM_COLOR      0x1f
+
+static int SortRGBAxis;
+
+typedef struct QuantizedColorType {
+    GifByteType RGB[3];
+    GifByteType NewColorIndex;
+    long Count;
+    struct QuantizedColorType *Pnext;
+} QuantizedColorType;
+
+typedef struct NewColorMapType {
+    GifByteType RGBMin[3], RGBWidth[3];
+    unsigned int NumEntries; /* # of QuantizedColorType in linked list below */
+    unsigned long Count; /* Total number of pixels in all the entries */
+    QuantizedColorType *QuantizedColors;
+} NewColorMapType;
+
+
+/****************************************************************************
+ * Routine called by qsort to compare two entries.
+ ****************************************************************************/
+static int
+SortCmpRtn(const void *Entry1,
+           const void *Entry2) {
+
+    return (*((QuantizedColorType **) Entry1))->RGB[SortRGBAxis] -
+       (*((QuantizedColorType **) Entry2))->RGB[SortRGBAxis];
+}
+
+/******************************************************************************
+ * Routine to subdivide the RGB space recursively using median cut in each
+ * axes alternatingly until ColorMapSize different cubes exists.
+ * The biggest cube in one dimension is subdivide unless it has only one entry.
+ * Returns GIF_ERROR if failed, otherwise GIF_OK.
+ ******************************************************************************/
+static int
+SubdivColorMap(NewColorMapType * NewColorSubdiv,
+               unsigned int ColorMapSize,
+               unsigned int *NewColorMapSize) {
+
+    int MaxSize;
+    unsigned int i, j, Index = 0, NumEntries, MinColor, MaxColor;
+    long Sum, Count;
+    QuantizedColorType *QuantizedColor, **SortArray;
+
+    while (ColorMapSize > *NewColorMapSize) {
+        /* Find candidate for subdivision: */
+        MaxSize = -1;
+        for (i = 0; i < *NewColorMapSize; i++) {
+            for (j = 0; j < 3; j++) {
+                if ((((int)NewColorSubdiv[i].RGBWidth[j]) > MaxSize) &&
+                      (NewColorSubdiv[i].NumEntries > 1)) {
+                    MaxSize = NewColorSubdiv[i].RGBWidth[j];
+                    Index = i;
+                    SortRGBAxis = j;
+                }
+            }
+        }
+
+        if (MaxSize == -1)
+            return GIF_OK;
+
+        /* Split the entry Index into two along the axis SortRGBAxis: */
+
+        /* Sort all elements in that entry along the given axis and split at
+         * the median.  */
+        SortArray = (QuantizedColorType **)malloc(
+                      sizeof(QuantizedColorType *) *
+                      NewColorSubdiv[Index].NumEntries);
+        if (SortArray == NULL)
+            return GIF_ERROR;
+        for (j = 0, QuantizedColor = NewColorSubdiv[Index].QuantizedColors;
+             j < NewColorSubdiv[Index].NumEntries && QuantizedColor != NULL;
+             j++, QuantizedColor = QuantizedColor->Pnext)
+            SortArray[j] = QuantizedColor;
+
+        qsort(SortArray, NewColorSubdiv[Index].NumEntries,
+              sizeof(QuantizedColorType *), SortCmpRtn);
+
+        /* Relink the sorted list into one: */
+        for (j = 0; j < NewColorSubdiv[Index].NumEntries - 1; j++)
+            SortArray[j]->Pnext = SortArray[j + 1];
+        SortArray[NewColorSubdiv[Index].NumEntries - 1]->Pnext = NULL;
+        NewColorSubdiv[Index].QuantizedColors = QuantizedColor = SortArray[0];
+        free((char *)SortArray);
+
+        /* Now simply add the Counts until we have half of the Count: */
+        Sum = NewColorSubdiv[Index].Count / 2 - QuantizedColor->Count;
+        NumEntries = 1;
+        Count = QuantizedColor->Count;
+        while (QuantizedColor->Pnext != NULL &&
+              (Sum -= QuantizedColor->Pnext->Count) >= 0 &&
+               QuantizedColor->Pnext->Pnext != NULL) {
+            QuantizedColor = QuantizedColor->Pnext;
+            NumEntries++;
+            Count += QuantizedColor->Count;
+        }
+        /* Save the values of the last color of the first half, and first
+         * of the second half so we can update the Bounding Boxes later.
+         * Also as the colors are quantized and the BBoxes are full 0..255,
+         * they need to be rescaled.
+         */
+        MaxColor = QuantizedColor->RGB[SortRGBAxis]; /* Max. of first half */
+       /* coverity[var_deref_op] */
+        MinColor = QuantizedColor->Pnext->RGB[SortRGBAxis]; /* of second */
+        MaxColor <<= (8 - BITS_PER_PRIM_COLOR);
+        MinColor <<= (8 - BITS_PER_PRIM_COLOR);
+
+        /* Partition right here: */
+        NewColorSubdiv[*NewColorMapSize].QuantizedColors =
+           QuantizedColor->Pnext;
+        QuantizedColor->Pnext = NULL;
+        NewColorSubdiv[*NewColorMapSize].Count = Count;
+        NewColorSubdiv[Index].Count -= Count;
+        NewColorSubdiv[*NewColorMapSize].NumEntries =
+           NewColorSubdiv[Index].NumEntries - NumEntries;
+        NewColorSubdiv[Index].NumEntries = NumEntries;
+        for (j = 0; j < 3; j++) {
+            NewColorSubdiv[*NewColorMapSize].RGBMin[j] =
+               NewColorSubdiv[Index].RGBMin[j];
+            NewColorSubdiv[*NewColorMapSize].RGBWidth[j] =
+               NewColorSubdiv[Index].RGBWidth[j];
+        }
+        NewColorSubdiv[*NewColorMapSize].RGBWidth[SortRGBAxis] =
+           NewColorSubdiv[*NewColorMapSize].RGBMin[SortRGBAxis] +
+           NewColorSubdiv[*NewColorMapSize].RGBWidth[SortRGBAxis] - MinColor;
+        NewColorSubdiv[*NewColorMapSize].RGBMin[SortRGBAxis] = MinColor;
+
+        NewColorSubdiv[Index].RGBWidth[SortRGBAxis] =
+           MaxColor - NewColorSubdiv[Index].RGBMin[SortRGBAxis];
+
+        (*NewColorMapSize)++;
+    }
+
+    return GIF_OK;
+}
+
+/******************************************************************************
+ * Quantize high resolution image into lower one. Input image consists of a
+ * 2D array for each of the RGB colors with size Width by Height. There is no
+ * Color map for the input. Output is a quantized image with 2D array of
+ * indexes into the output color map.
+ *   Note input image can be 24 bits at the most (8 for red/green/blue) and
+ * the output has 256 colors at the most (256 entries in the color map.).
+ * ColorMapSize specifies size of color map up to 256 and will be updated to
+ * real size before returning.
+ *   Also non of the parameter are allocated by this routine.
+ *   This function returns GIF_OK if succesfull, GIF_ERROR otherwise.
+ ******************************************************************************/
+static int
+QuantizeBuffer(unsigned int Width,
+               unsigned int Height,
+               int *ColorMapSize,
+               GifByteType * RedInput,
+               GifByteType * GreenInput,
+               GifByteType * BlueInput,
+               GifByteType * OutputBuffer,
+               GifColorType * OutputColorMap) {
+
+    unsigned int Index, NumOfEntries;
+    int i, j, MaxRGBError[3];
+    unsigned int NewColorMapSize;
+    long Red, Green, Blue;
+    NewColorMapType NewColorSubdiv[256];
+    QuantizedColorType *ColorArrayEntries, *QuantizedColor;
+
+    ColorArrayEntries = (QuantizedColorType *)malloc(
+                           sizeof(QuantizedColorType) * COLOR_ARRAY_SIZE);
+    if (ColorArrayEntries == NULL) {
+        return GIF_ERROR;
+    }
+
+    for (i = 0; i < COLOR_ARRAY_SIZE; i++) {
+        ColorArrayEntries[i].RGB[0] = i >> (2 * BITS_PER_PRIM_COLOR);
+        ColorArrayEntries[i].RGB[1] = (i >> BITS_PER_PRIM_COLOR) &
+           MAX_PRIM_COLOR;
+        ColorArrayEntries[i].RGB[2] = i & MAX_PRIM_COLOR;
+        ColorArrayEntries[i].Count = 0;
+    }
+
+    /* Sample the colors and their distribution: */
+    for (i = 0; i < (int)(Width * Height); i++) {
+        Index = ((RedInput[i] >> (8 - BITS_PER_PRIM_COLOR)) <<
+                  (2 * BITS_PER_PRIM_COLOR)) +
+                ((GreenInput[i] >> (8 - BITS_PER_PRIM_COLOR)) <<
+                  BITS_PER_PRIM_COLOR) +
+                (BlueInput[i] >> (8 - BITS_PER_PRIM_COLOR));
+        ColorArrayEntries[Index].Count++;
+    }
+
+    /* Put all the colors in the first entry of the color map, and call the
+     * recursive subdivision process.  */
+    for (i = 0; i < 256; i++) {
+        NewColorSubdiv[i].QuantizedColors = NULL;
+        NewColorSubdiv[i].Count = NewColorSubdiv[i].NumEntries = 0;
+        for (j = 0; j < 3; j++) {
+            NewColorSubdiv[i].RGBMin[j] = 0;
+            NewColorSubdiv[i].RGBWidth[j] = 255;
+        }
+    }
+
+    /* Find the non empty entries in the color table and chain them: */
+    for (i = 0; i < COLOR_ARRAY_SIZE; i++)
+        if (ColorArrayEntries[i].Count > 0)
+            break;
+    QuantizedColor = NewColorSubdiv[0].QuantizedColors = &ColorArrayEntries[i];
+    NumOfEntries = 1;
+    while (++i < COLOR_ARRAY_SIZE)
+        if (ColorArrayEntries[i].Count > 0) {
+            QuantizedColor->Pnext = &ColorArrayEntries[i];
+            QuantizedColor = &ColorArrayEntries[i];
+            NumOfEntries++;
+        }
+    QuantizedColor->Pnext = NULL;
+
+    NewColorSubdiv[0].NumEntries = NumOfEntries; /* Different sampled colors */
+    NewColorSubdiv[0].Count = ((long)Width) * Height; /* Pixels */
+    NewColorMapSize = 1;
+    if (SubdivColorMap(NewColorSubdiv, *ColorMapSize, &NewColorMapSize) !=
+       GIF_OK) {
+        free((char *)ColorArrayEntries);
+        return GIF_ERROR;
+    }
+    if (NewColorMapSize < *ColorMapSize) {
+        /* And clear rest of color map: */
+        for (i = NewColorMapSize; i < *ColorMapSize; i++)
+            OutputColorMap[i].Red = OutputColorMap[i].Green =
+                OutputColorMap[i].Blue = 0;
+    }
+
+    /* Average the colors in each entry to be the color to be used in the
+     * output color map, and plug it into the output color map itself. */
+    for (i = 0; i < NewColorMapSize; i++) {
+        if ((j = NewColorSubdiv[i].NumEntries) > 0) {
+            QuantizedColor = NewColorSubdiv[i].QuantizedColors;
+            Red = Green = Blue = 0;
+            while (QuantizedColor) {
+                QuantizedColor->NewColorIndex = i;
+                Red += QuantizedColor->RGB[0];
+                Green += QuantizedColor->RGB[1];
+                Blue += QuantizedColor->RGB[2];
+                QuantizedColor = QuantizedColor->Pnext;
+            }
+            OutputColorMap[i].Red = (Red << (8 - BITS_PER_PRIM_COLOR)) / j;
+            OutputColorMap[i].Green = (Green << (8 - BITS_PER_PRIM_COLOR)) / j;
+            OutputColorMap[i].Blue = (Blue << (8 - BITS_PER_PRIM_COLOR)) / j;
+        } else
+            fprintf(stderr,
+                    "\n%s: Null entry in quantized color map - that's weird.\n",
+                    "libgdiplus");
+    }
+
+    /* Finally scan the input buffer again and put the mapped index in the
+     * output buffer.  */
+    MaxRGBError[0] = MaxRGBError[1] = MaxRGBError[2] = 0;
+    for (i = 0; i < (int)(Width * Height); i++) {
+        Index = ((RedInput[i] >> (8 - BITS_PER_PRIM_COLOR)) <<
+                 (2 * BITS_PER_PRIM_COLOR)) +
+                ((GreenInput[i] >> (8 - BITS_PER_PRIM_COLOR)) <<
+                 BITS_PER_PRIM_COLOR) +
+                (BlueInput[i] >> (8 - BITS_PER_PRIM_COLOR));
+        Index = ColorArrayEntries[Index].NewColorIndex;
+        OutputBuffer[i] = Index;
+        if (MaxRGBError[0] < ABS(OutputColorMap[Index].Red - RedInput[i]))
+            MaxRGBError[0] = ABS(OutputColorMap[Index].Red - RedInput[i]);
+        if (MaxRGBError[1] < ABS(OutputColorMap[Index].Green - GreenInput[i]))
+            MaxRGBError[1] = ABS(OutputColorMap[Index].Green - GreenInput[i]);
+        if (MaxRGBError[2] < ABS(OutputColorMap[Index].Blue - BlueInput[i]))
+            MaxRGBError[2] = ABS(OutputColorMap[Index].Blue - BlueInput[i]);
+    }
+
+#ifdef DEBUG
+    fprintf(stderr,
+            "Quantization L(0) errors: Red = %d, Green = %d, Blue = %d.\n",
+            MaxRGBError[0], MaxRGBError[1], MaxRGBError[2]);
+#endif /* DEBUG */
+
+    free((char *)ColorArrayEntries);
+
+    *ColorMapSize = NewColorMapSize;
+
+    return GIF_OK;
+}
+ 
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
 
@@ -60,9 +366,13 @@ int GIFCodec::readImage (std::istream* s
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
   
@@ -74,7 +384,11 @@ int GIFCodec::readImage (std::istream* s
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
     
@@ -83,7 +397,11 @@ int GIFCodec::readImage (std::istream* s
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
       
@@ -104,7 +422,11 @@ int GIFCodec::readImage (std::istream* s
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
@@ -113,7 +435,11 @@ int GIFCodec::readImage (std::istream* s
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
@@ -122,12 +448,20 @@ int GIFCodec::readImage (std::istream* s
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
@@ -155,7 +489,11 @@ int GIFCodec::readImage (std::istream* s
   // convert colormap to our 16bit "TIFF"format
   colorspace_de_palette (image, ColorMap->ColorCount, rmap, gmap, bmap);
   
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
   EGifCloseFile(GifFile, &GifError);
+#else
+  EGifCloseFile(GifFile);
+#endif
 
   return true;
 }
@@ -167,7 +505,11 @@ bool GIFCodec::writeImage (std::ostream*
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
@@ -176,7 +518,11 @@ bool GIFCodec::writeImage (std::ostream*
   int ColorMapSize = 256;
   
   // later use our own colormap generation
+#if GIFLIB_MAJOR >= 5
   ColorMapObject* OutputColorMap = GifMakeMapObject(ColorMapSize, 0);
+#else
+  ColorMapObject* OutputColorMap = MakeMapObject(ColorMapSize, 0);
+#endif
   if (!OutputColorMap)
     return false;
   
@@ -204,7 +550,7 @@ bool GIFCodec::writeImage (std::ostream*
   }
    
   
-  if (GifQuantizeBuffer(image.w, image.h, &ColorMapSize,
+  if (QuantizeBuffer(image.w, image.h, &ColorMapSize,
 		     RedBuffer, GreenBuffer, BlueBuffer,
 		     OutputBuffer, OutputColorMap->Colors) == GIF_ERROR) {
     return false;
@@ -235,7 +581,11 @@ bool GIFCodec::writeImage (std::ostream*
 
   delete[] RedBuffer; delete[] GreenBuffer; delete[] BlueBuffer;
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
   EGifCloseFile(GifFile, &GifError);
+#else
+  EGifCloseFile(GifFile);
+#endif
   return true;
 }
 
