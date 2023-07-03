--- lib/kpaexif/Database.cpp.orig	2023-03-25 09:46:12 UTC
+++ lib/kpaexif/Database.cpp
@@ -320,7 +320,7 @@ bool Exif::Database::add(const DB::FileName &fileName)
         return false;
 
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(fileName.absolute().toLocal8Bit().data());
+        Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(fileName.absolute().toLocal8Bit().data()) };
         Q_ASSERT(image.get() != nullptr);
         image->readMetadata();
         Exiv2::ExifData &exifData = image->exifData();
@@ -341,7 +341,7 @@ bool Exif::Database::add(const DB::FileNameList &list)
 
     for (const DB::FileName &fileName : list) {
         try {
-            Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(fileName.absolute().toLocal8Bit().data());
+            Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(fileName.absolute().toLocal8Bit().data()) };
             Q_ASSERT(image.get() != nullptr);
             image->readMetadata();
             map << DBExifInfo(fileName, image->exifData());
