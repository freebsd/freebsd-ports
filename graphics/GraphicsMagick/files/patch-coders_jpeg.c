--- coders/jpeg.c.orig	2022-12-26 16:56:04 UTC
+++ coders/jpeg.c
@@ -1,5 +1,5 @@
 /*
-% Copyright (C) 2003-2022 GraphicsMagick Group
+% Copyright (C) 2003-2023 GraphicsMagick Group
 % Copyright (C) 2002 ImageMagick Studio
 % Copyright 1991-1999 E. I. du Pont de Nemours and Company
 %
@@ -954,7 +954,7 @@ EstimateJPEGQuality(const struct jpeg_decompress_struc
     i;
 
   save_quality=0;
-#ifdef D_LOSSLESS_SUPPORTED
+#if !defined(LIBJPEG_TURBO_VERSION_NUMBER) && defined(D_LOSSLESS_SUPPORTED)
   if (image->compression==LosslessJPEGCompression)
     {
       save_quality=100;
@@ -1461,7 +1461,9 @@ static Image *ReadJPEGImage(const ImageInfo *image_inf
     }
 #endif
 #if (JPEG_LIB_VERSION >= 61) && defined(D_PROGRESSIVE_SUPPORTED)
-#ifdef D_LOSSLESS_SUPPORTED
+#if !defined(LIBJPEG_TURBO_VERSION_NUMBER) && defined(D_LOSSLESS_SUPPORTED)
+  /* This code is based on a patch to IJG JPEG 6b, or somesuch.  Standard
+     library does not have a 'process' member. */
   image->interlace=
     jpeg_info.process == JPROC_PROGRESSIVE ? LineInterlace : NoInterlace;
   image->compression=jpeg_info.process == JPROC_LOSSLESS ?
@@ -1693,7 +1695,7 @@ static Image *ReadJPEGImage(const ImageInfo *image_inf
         }
     }
 
-  jpeg_pixels=MagickAllocateResourceLimitedArray(JSAMPLE *,
+  jpeg_pixels=MagickAllocateResourceLimitedClearedArray(JSAMPLE *,
                                   jpeg_info.output_components,
                                   MagickArraySize(image->columns,
                                                   sizeof(JSAMPLE)));
@@ -1702,9 +1704,6 @@ static Image *ReadJPEGImage(const ImageInfo *image_inf
       jpeg_destroy_decompress(&jpeg_info);
       ThrowJPEGReaderException(ResourceLimitError,MemoryAllocationFailed,image);
     }
-  (void) memset(jpeg_pixels,0,MagickArraySize(jpeg_info.output_components,
-                                              MagickArraySize(image->columns,
-                                                              sizeof(JSAMPLE))));
 
   /*
     Extended longjmp-based error handler (with jpeg_pixels)
@@ -2791,7 +2790,8 @@ static MagickPassFail WriteJPEGImage(const ImageInfo *
     (void) LogMagickEvent(CoderEvent,GetMagickModule(),
       "Image resolution: %ld,%ld",(long) image->x_resolution,
       (long) image->y_resolution);
-  if ((image->x_resolution != 0) && (image->y_resolution != 0))
+  if ((image->x_resolution >= 0) && (image->x_resolution < (double) SHRT_MAX) &&
+      (image->y_resolution >= 0) && (image->y_resolution < (double) SHRT_MAX))
     {
       /*
         Set image resolution.
@@ -2896,7 +2896,7 @@ static MagickPassFail WriteJPEGImage(const ImageInfo *
   if ((image->compression == LosslessJPEGCompression) ||
       (quality > 100))
     {
-#if defined(C_LOSSLESS_SUPPORTED)
+#if !defined(LIBJPEG_TURBO_VERSION_NUMBER) && defined(C_LOSSLESS_SUPPORTED)
       if (quality < 100)
         ThrowException(&image->exception,CoderWarning,
                        LosslessToLossyJPEGConversion,(char *) NULL);
