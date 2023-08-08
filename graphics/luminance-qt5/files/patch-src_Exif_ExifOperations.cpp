--- src/Exif/ExifOperations.cpp.orig	2021-01-11 09:41:28 UTC
+++ src/Exif/ExifOperations.cpp
@@ -108,12 +108,12 @@ void copyExifData(const std::string &from, const std::
 #endif
 
     try {
-        Exiv2::Image::AutoPtr sourceImage;
+        Exiv2::Image::UniquePtr sourceImage;
         Exiv2::ExifData srcExifData;
 
         if (!from.empty()) {
             // get source exif data
-            sourceImage = Exiv2::ImageFactory::open(from);
+            sourceImage = std::move(Exiv2::ImageFactory::open(from));
 
             sourceImage->readMetadata();
             srcExifData = sourceImage->exifData();
@@ -128,7 +128,7 @@ void copyExifData(const std::string &from, const std::
         }
 
         // get destination exif data
-        Exiv2::Image::AutoPtr destinationImage = Exiv2::ImageFactory::open(to);
+        Exiv2::Image::UniquePtr destinationImage = Exiv2::ImageFactory::open(to);
 
         if (dontOverwrite) {
             // doesn't throw anything if it is empty
@@ -212,7 +212,7 @@ void copyExifData(const std::string &from, const std::
             destinationImage->setExifData(srcExifData);
         }
         destinationImage->writeMetadata();
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
 #ifndef NDEBUG
         qDebug() << e.what();
 #endif
@@ -250,7 +250,7 @@ float obtain_avg_lum(const std::string& filename)
 {
     try
     {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         Exiv2::ExifData &exifData = image->exifData();
         if (exifData.empty())
@@ -329,7 +329,7 @@ allowed for ev computation purposes.
             return -1;
         }
     }
-    catch (Exiv2::AnyError& e)
+    catch (Exiv2::Error& e)
     {
         return -1;
     }
@@ -338,7 +338,7 @@ allowed for ev computation purposes.
 
 float getExposureTime(const std::string &filename) {
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         Exiv2::ExifData &exifData = image->exifData();
         if (exifData.empty()) return -1;
@@ -374,14 +374,14 @@ float getExposureTime(const std::string &filename) {
         } else {
             return -1;
         }
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
         return -1;
     }
 }
 
 float getAverageLuminance(const std::string &filename) {
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(filename);
         image->readMetadata();
         Exiv2::ExifData &exifData = image->exifData();
 
@@ -403,7 +403,7 @@ float getAverageLuminance(const std::string &filename)
                   << std::endl;
 
         return -1.0;
-    } catch (Exiv2::AnyError &e) {
+    } catch (Exiv2::Error &e) {
         return -1.0;
     }
 }
