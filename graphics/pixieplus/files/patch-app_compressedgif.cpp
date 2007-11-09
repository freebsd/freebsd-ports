--- app/compressedgif.cpp	2004-05-22 10:02:26.000000000 -0400
+++ app/compressedgif.cpp	2007-11-08 08:44:00.000000000 -0500
@@ -7,5 +7,5 @@
 #include <time.h>
 #include <sys/types.h>
-#include <api.h>
+#include <magick/api.h>
 #include <assert.h>
 
@@ -28,5 +28,6 @@
 #endif
 
-#if (MagickLibVersion < 0x0554)
+/* GraphicsMagick uses much higher "base" for version numbers: */
+#if (MagickLibVersion < 0x0554) || (MagickLibVersion > 0x0100000)
 #warning Using pre-ImageMagick 5.5.4 tags
 #define SaveImageTag SaveImageText
@@ -360,5 +361,9 @@
   status=OpenBlob(image_info,image,WriteBinaryBlobMode,&image->exception);
   if (status == false)
+#if (MagickLibVersion > 0x0100000) /* GraphicsMagick - must pass image */
+    ThrowWriterException(FileOpenError,"Unable to open file", image);
+#else
     ThrowWriterException(FileOpenError,"Unable to open file");
+#endif
   /*
     Determine image bounding box.
@@ -385,5 +390,9 @@
   if ((global_colormap == (unsigned char *) NULL) ||
       (colormap == (unsigned char *) NULL))
+#if (MagickLibVersion > 0x0100000) /* GraphicsMagick - must pass image */
+    ThrowWriterException(ResourceLimitError,"Memory allocation failed", image);
+#else
     ThrowWriterException(ResourceLimitError,"Memory allocation failed");
+#endif
   for (i=0; i < 768; i++)
     colormap[i]=0;
@@ -437,6 +446,11 @@
                 LiberateMemory((void **) &global_colormap);
                 LiberateMemory((void **) &colormap);
+#if (MagickLibVersion > 0x0100000) /* GraphicsMagick - must pass image */
+                ThrowWriterException(ResourceLimitError,
+                  "Memory allocation failed", image);
+#else
                 ThrowWriterException(ResourceLimitError,
                   "Memory allocation failed")
+#endif
               }
             image->colormap[opacity]=image->background_color;
@@ -615,5 +629,9 @@
         LiberateMemory((void **) &global_colormap);
         LiberateMemory((void **) &colormap);
+#if (MagickLibVersion > 0x0100000) /* GraphicsMagick - must pass image */
+        ThrowWriterException(ResourceLimitError,"Memory allocation failed", image);
+#else
         ThrowWriterException(ResourceLimitError,"Memory allocation failed")
+#endif
       }
     (void) WriteBlobByte(image,0x0);
