--- ./libs/dimg/loaders/pngloader.cpp.orig	2010-01-31 23:21:36.000000000 +1000
+++ ./libs/dimg/loaders/pngloader.cpp	2010-02-04 11:16:41.771939164 +1000
@@ -105,7 +105,11 @@
     unsigned char buf[PNG_BYTES_TO_CHECK];
 
     size_t membersRead = fread(buf, 1, PNG_BYTES_TO_CHECK, f);
+#if PNG_LIBPNG_VER >= 10400
+    if ((membersRead != PNG_BYTES_TO_CHECK) || png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
+#else
     if ((membersRead != PNG_BYTES_TO_CHECK) || !png_check_sig(buf, PNG_BYTES_TO_CHECK))
+#endif
     {
         kDebug() << "Not a PNG image file.";
         fclose(f);
@@ -165,7 +169,11 @@
     CleanupData *cleanupData = new CleanupData;
     cleanupData->setFile(f);
 
+#if PNG_LIBPNG_VER >= 10400
+    if (setjmp(png_jmpbuf(png_ptr)))
+#else
     if (setjmp(png_ptr->jmpbuf))
+#endif
     {
         kDebug() << "Internal libPNG error during reading file. Process aborted!";
         png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
@@ -322,7 +330,11 @@
 #ifdef ENABLE_DEBUG_MESSAGES
                     kDebug() << "PNG in PNG_COLOR_TYPE_GRAY";
 #endif
+#if PNG_LIBPNG_VER >= 10400
+                    png_set_expand_gray_1_2_4_to_8(png_ptr);
+#else
                     png_set_gray_1_2_4_to_8(png_ptr);
+#endif
                     png_set_gray_to_rgb(png_ptr);
 
                     if (QSysInfo::ByteOrder == QSysInfo::LittleEndian)           // Intel
@@ -627,7 +639,11 @@
     CleanupData *cleanupData = new CleanupData;
     cleanupData->setFile(f);
 
-    if (setjmp(png_ptr->jmpbuf))
+#if PNG_LIBPNG_VER >= 10400
+    if (setjmp(png_jmpbuf(png_ptr)))
+#else
+     if (setjmp(png_ptr->jmpbuf))
+#endif
     {
         kDebug() << "Internal libPNG error during writing file. Process aborted!";
         png_destroy_write_struct(&png_ptr, (png_infopp) & info_ptr);
