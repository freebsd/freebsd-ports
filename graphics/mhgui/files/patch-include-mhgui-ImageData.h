--- include/mhgui/ImageData.h.orig	2007-12-12 22:07:20.000000000 +0100
+++ include/mhgui/ImageData.h	2010-03-29 18:24:59.000000000 +0200
@@ -67,7 +67,7 @@
 private:
   char         *image_data; /* raw png image data */
   char         *end_bufferPtr;
-  unsigned long width, height;
+  png_uint_32	width, height;
   unsigned int  bytesPerRow;
   bool          alpha;
 
