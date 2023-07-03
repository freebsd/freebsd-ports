--- lib/kpaexif/Info.cpp.orig	2023-07-02 23:13:17 UTC
+++ lib/kpaexif/Info.cpp
@@ -166,7 +166,7 @@ Info::Info()
 void Exif::writeExifInfoToFile(const DB::FileName &srcName, const QString &destName, const QString &imageDescription)
 {
     // Load Exif from source image
-    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(QFile::encodeName(srcName.absolute()).data());
+    Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(QFile::encodeName(srcName.absolute()).data()) };
     image->readMetadata();
     Exiv2::ExifData data = image->exifData();
 
@@ -201,7 +201,7 @@ Exif::Metadata Exif::Info::metadata(const DB::FileName
 {
     try {
         Exif::Metadata result;
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(QFile::encodeName(fileName.absolute()).data());
+        Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(QFile::encodeName(fileName.absolute()).data()) };
         Q_ASSERT(image.get() != nullptr);
         image->readMetadata();
         result.exif = image->exifData();
