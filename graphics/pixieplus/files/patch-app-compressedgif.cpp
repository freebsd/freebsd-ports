--- app/compressedgif.cpp.orig	Fri May 21 14:05:50 2004
+++ app/compressedgif.cpp	Fri May 21 14:28:14 2004
@@ -63,7 +63,7 @@
     if (byte_count >= 254) \
       { \
         (void) WriteBlobByte(image,byte_count); \
-        (void) WriteBlob(image,byte_count,(char *) packet); \
+        (void) WriteBlob(image,byte_count,(const unsigned char *) packet); \
         byte_count=0; \
       } \
     datum>>=8; \
@@ -280,7 +280,7 @@
       if (byte_count >= 254)
         {
           (void) WriteBlobByte(image,byte_count);
-          (void) WriteBlob(image,byte_count,(char *) packet);
+          (void) WriteBlob(image,byte_count,(const unsigned char *) packet);
           byte_count=0;
         }
     }
@@ -290,7 +290,7 @@
   if (byte_count > 0)
     {
       (void) WriteBlobByte(image,byte_count);
-      (void) WriteBlob(image,byte_count,(char *) packet);
+      (void) WriteBlob(image,byte_count,(const unsigned char *) packet);
     }
   /*
     Free encoder memory.
@@ -359,7 +359,7 @@
   assert(image->signature == MagickSignature);
   status=OpenBlob(image_info,image,WriteBinaryBlobMode,&image->exception);
   if (status == false)
-    ThrowWriterException(FileOpenError,"Unable to open file",image);
+    ThrowWriterException(FileOpenError,"Unable to open file");
   /*
     Determine image bounding box.
   */
@@ -384,7 +384,7 @@
   colormap=(unsigned char *) AcquireMemory(768);
   if ((global_colormap == (unsigned char *) NULL) ||
       (colormap == (unsigned char *) NULL))
-    ThrowWriterException(ResourceLimitError,"Memory allocation failed",image);
+    ThrowWriterException(ResourceLimitError,"Memory allocation failed");
   for (i=0; i < 768; i++)
     colormap[i]=0;
   /*
@@ -392,12 +392,12 @@
   */
   if ((GetImageAttribute(image,"comment") == (ImageAttribute *) NULL) &&
       !image_info->adjoin && !image->matte)
-    (void) WriteBlob(image,6,"GIF87a");
+    (void) WriteBlob(image,6,(const unsigned char*)"GIF87a");
   else
     if (LocaleCompare(image_info->magick,"GIF87") == 0)
-      (void) WriteBlob(image,6,"GIF87a");
+      (void) WriteBlob(image,6,(const unsigned char*)"GIF87a");
     else
-      (void) WriteBlob(image,6,"GIF89a");
+      (void) WriteBlob(image,6,(const unsigned char*)"GIF89a");
   page.x=image->page.x;
   page.y=image->page.y;
   if ((image->page.width != 0) && (image->page.height != 0))
@@ -437,7 +437,7 @@
                 LiberateMemory((void **) &global_colormap);
                 LiberateMemory((void **) &colormap);
                 ThrowWriterException(ResourceLimitError,
-                  "Memory allocation failed",image)
+                  "Memory allocation failed")
               }
             image->colormap[opacity]=image->background_color;
             for (y=0; y < (long) image->rows; y++)
@@ -515,7 +515,7 @@
             break;
         (void) WriteBlobByte(image,(long) j);  /* background color */
         (void) WriteBlobByte(image,0x0);  /* reserved */
-        (void) WriteBlob(image,3*(1 << bits_per_pixel),(char *) colormap);
+        (void) WriteBlob(image,3*(1 << bits_per_pixel),(const unsigned char*)colormap);
         for (j=0; j < 768; j++)
           global_colormap[j]=colormap[j];
       }
@@ -570,7 +570,7 @@
             (void) WriteBlobByte(image,0x21);
             (void) WriteBlobByte(image,0xff);
             (void) WriteBlobByte(image,0x0b);
-            (void) WriteBlob(image,11,"NETSCAPE2.0");
+            (void) WriteBlob(image,11,(const unsigned char*)"NETSCAPE2.0");
             (void) WriteBlobByte(image,0x03);
             (void) WriteBlobByte(image,0x01);
             (void) WriteBlobLSBShort(image,image->iterations);
@@ -602,7 +602,7 @@
         c|=0x80;
         c|=(bits_per_pixel-1);   /* size of local colormap */
         (void) WriteBlobByte(image,c);
-        (void) WriteBlob(image,3*(1 << bits_per_pixel),(char *) colormap);
+        (void) WriteBlob(image,3*(1 << bits_per_pixel),(const unsigned char*) colormap);
       }
     /*
       Write the image data.
@@ -614,8 +614,7 @@
       {
         LiberateMemory((void **) &global_colormap);
         LiberateMemory((void **) &colormap);
-        ThrowWriterException(ResourceLimitError,"Memory allocation failed",
-          image)
+        ThrowWriterException(ResourceLimitError,"Memory allocation failed")
       }
     (void) WriteBlobByte(image,0x0);
     if (image->next == (Image *) NULL)
