--- Sources/ptImageHelper.cpp.orig	2023-07-02 14:41:47 UTC
+++ Sources/ptImageHelper.cpp
@@ -34,6 +34,7 @@
 #pragma GCC diagnostic pop
 #include <wand/magick_wand.h>
 
+#include <iostream>
 #include <vector>
 #include <QStringList>
 
@@ -106,7 +107,7 @@ bool ptImageHelper::WriteExif(const QString           
       if (!AFileName.endsWith(JpegExtensions.at(i))) deleteDNGdata = true;
     }
 
-    Exiv2::Image::AutoPtr Exiv2Image = Exiv2::ImageFactory::open(AFileName.toLocal8Bit().data());
+    Exiv2::Image::UniquePtr Exiv2Image = Exiv2::ImageFactory::open(AFileName.toLocal8Bit().data());
 
     Exiv2Image->readMetadata();
     Exiv2::ExifData outExifData = Exiv2Image->exifData();
@@ -176,7 +177,7 @@ bool ptImageHelper::WriteExif(const QString           
     Exiv2Image->writeMetadata();
     return true;
 #endif
-  } catch (Exiv2::AnyError& Error) {
+  } catch (Exiv2::Error& Error) {
     if (Settings->GetInt("JobMode") == 0) {
       ptMessageBox::warning(0 ,"Exiv2 Error","No exif data written!\nCaught Exiv2 exception '" + QString(Error.what()) + "'\n");
     } else {
@@ -198,7 +199,7 @@ bool ptImageHelper::ReadExif(const QString        &AFi
     if (Exiv2::ImageFactory::getType(AFileName.toLocal8Bit().data()) == Exiv2::ImageType::none)
       return false;
 
-    Exiv2::Image::AutoPtr hImage = Exiv2::ImageFactory::open(AFileName.toLocal8Bit().data());
+    Exiv2::Image::UniquePtr hImage = Exiv2::ImageFactory::open(AFileName.toLocal8Bit().data());
 
     if (!hImage.get()) return false;
 
@@ -295,19 +296,19 @@ bool ptImageHelper::TransferExif(const QString ASource
     if (Exiv2::ImageFactory::getType(ASourceFile.toLocal8Bit().data()) == Exiv2::ImageType::none)
       return false;
 
-    Exiv2::Image::AutoPtr hSourceImage = Exiv2::ImageFactory::open(ASourceFile.toLocal8Bit().data());
+    Exiv2::Image::UniquePtr hSourceImage = Exiv2::ImageFactory::open(ASourceFile.toLocal8Bit().data());
 
     if (!hSourceImage.get()) return false;
 
     hSourceImage->readMetadata();
 
-    Exiv2::Image::AutoPtr hTargetImage = Exiv2::ImageFactory::open(ATargetFile.toLocal8Bit().data());
+    Exiv2::Image::UniquePtr hTargetImage = Exiv2::ImageFactory::open(ATargetFile.toLocal8Bit().data());
 
     hTargetImage->clearMetadata();
     hTargetImage->setMetadata(*hSourceImage);
     hTargetImage->writeMetadata();
     return true;
-  } catch (Exiv2::AnyError& Error) {
+  } catch (Exiv2::Error& Error) {
     if (Settings->GetInt("JobMode") == 0) {
       ptMessageBox::warning(0 ,"Exiv2 Error","No exif data written!\nCaught Exiv2 exception '" + QString(Error.what()) + "'\n");
     } else {
