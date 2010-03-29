--- digikam/libs/dimg/loaders/pngloader.cpp.orig	2009-07-03 07:19:41.000000000 +0200
+++ digikam/libs/dimg/loaders/pngloader.cpp	2010-03-29 18:35:49.000000000 +0200
@@ -88,7 +88,11 @@
     unsigned char buf[PNG_BYTES_TO_CHECK];
 
     fread(buf, 1, PNG_BYTES_TO_CHECK, f);
+#if PNG_LIBPNG_VER >= 10400
+    if (png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
+#else
     if (!png_check_sig(buf, PNG_BYTES_TO_CHECK))
+#endif
     {
         DDebug() << k_funcinfo << "Not a PNG image file." << endl;
         fclose(f);
@@ -120,7 +124,11 @@
     // PNG error handling. If an error occurs during reading, libpng
     // will jump here
 
+#if PNG_LIBPNG_VER >= 10400
+    if (setjmp(png_jmpbuf(png_ptr)))
+#else
     if (setjmp(png_ptr->jmpbuf))
+#endif
     {
         DDebug() << k_funcinfo << "Internal libPNG error during reading file. Process aborted!" << endl;
         png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
@@ -252,7 +260,11 @@
 #ifdef ENABLE_DEBUG_MESSAGES
                 DDebug() << "PNG in PNG_COLOR_TYPE_GRAY" << endl;
 #endif
+#if PNG_LIBPNG_VER >= 10400
+                png_set_expand_gray_1_2_4_to_8(png_ptr);
+#else
                 png_set_gray_1_2_4_to_8(png_ptr);
+#endif
                 png_set_gray_to_rgb(png_ptr);
 
                 if (QImage::systemByteOrder() == QImage::LittleEndian)       // Intel
@@ -526,7 +538,11 @@
     // PNG error handling. If an error occurs during writing, libpng
     // will jump here
 
-    if (setjmp(png_ptr->jmpbuf))
+#if PNG_LIBPNG_VER >= 10400
+    if (setjmp(png_jmpbuf(png_ptr)))
+#else
+     if (setjmp(png_ptr->jmpbuf))
+#endif
     {
         DDebug() << k_funcinfo << "Internal libPNG error during writing file. Process aborted!" << endl;
         fclose(f);
