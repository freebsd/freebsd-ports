--- src/Docks/GeoImageDock.cpp.orig	2021-08-27 12:34:31 UTC
+++ src/Docks/GeoImageDock.cpp
@@ -456,7 +456,7 @@ void GeoImageDock::loadImages(QStringList fileNames)
     Document *theDocument = Main->document();
     MapView *theView = Main->view();
 
-    Exiv2::Image::AutoPtr image;
+    Exiv2::Image::UniquePtr image;
     Exiv2::ExifData exifData;
     bool positionValid = false;
 
@@ -868,7 +868,7 @@ void GeoImageDock::saveImage()
 //    fn = QFileDialog::getSaveFileName(0, "Specify output filename", fn, tr("JPEG Images (*.jpg)"));
     qDebug() << fn;
     if (!fn.isEmpty()) {
-        Exiv2::Image::AutoPtr imageIn, imageOut;
+        Exiv2::Image::UniquePtr imageIn, imageOut;
         Exiv2::ExifData exifData;
         try {
             imageIn = Exiv2::ImageFactory::open(usedTrackPoints.at(index).filename.toStdString());
@@ -892,7 +892,7 @@ Coord GeoImageDock::getGeoDataFromImage(const QString 
 {
     Coord pos;
     double lat = 0.0, lon = 0.0;
-    Exiv2::Image::AutoPtr image;
+    Exiv2::Image::UniquePtr image;
     Exiv2::ExifData exifData;
     bool positionValid = false;
 
@@ -932,7 +932,7 @@ Coord GeoImageDock::getGeoDataFromImage(const QString 
 
 void GeoImageDock::addGeoDataToImage(Coord position, const QString & file)
 {
-    Exiv2::Image::AutoPtr image;
+    Exiv2::Image::UniquePtr image;
 
     try {
         image = Exiv2::ImageFactory::open(file.toStdString());
