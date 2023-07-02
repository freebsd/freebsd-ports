--- src/Libpfs/exif/exifdata.cpp.orig	2021-01-11 09:41:28 UTC
+++ src/Libpfs/exif/exifdata.cpp
@@ -52,7 +52,7 @@ ExifData::ExifData(const std::string &filename) { from
 void ExifData::fromFile(const std::string &filename) {
     reset();
     try {
-        ::Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        ::Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         ::Exiv2::ExifData &exifData = image->exifData();
 
@@ -121,7 +121,7 @@ void ExifData::fromFile(const std::string &filename) {
          */
         if ((it = exifData.findKey(Exiv2::ExifKey("Exif.Image.Orientation"))) !=
             exifData.end()) {
-            long rotation = it->toLong();
+            long rotation = it->toInt64();
             switch (rotation) {
                 case 3:
                     m_orientation = 180;
@@ -134,7 +134,7 @@ void ExifData::fromFile(const std::string &filename) {
                     break;
             }
         }
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
         return;
     }
 }
