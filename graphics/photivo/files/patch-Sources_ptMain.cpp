--- Sources/ptMain.cpp.orig	2016-03-22 03:34:55 UTC
+++ Sources/ptMain.cpp
@@ -5325,7 +5325,7 @@ void ReadSidecar(const QString& Sidecar)
     return;
   }
 
-  Exiv2::Image::AutoPtr hImage = Exiv2::ImageFactory::open(Sidecar.toLocal8Bit().data());
+  Exiv2::Image::UniquePtr hImage = Exiv2::ImageFactory::open(Sidecar.toLocal8Bit().data());
 
   if (!hImage.get()) {
     return;
