--- src/gimplensfun.cpp.orig	2023-07-02 12:36:07 UTC
+++ src/gimplensfun.cpp
@@ -1034,7 +1034,7 @@ static void process_image (GimpDrawable *drawable) {
 //
 static int read_opts_from_exif(const char *filename) {
 
-    Exiv2::Image::AutoPtr Exiv2image;
+    Exiv2::Image::UniquePtr Exiv2image;
     Exiv2::ExifData exifData;
 
     const lfCamera  **cameras    = 0;
@@ -1062,7 +1062,7 @@ static int read_opts_from_exif(const char *filename) {
             return -1;
         }
     }
-    catch (Exiv2::AnyError& e) {
+    catch (Exiv2::Error& e) {
         if (DEBUG) {
             g_print ("exception on reading data. \n");
         }
