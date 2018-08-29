--- src/lprofqt/imageitem.cpp.orig	2008-03-06 21:18:58 UTC
+++ src/lprofqt/imageitem.cpp
@@ -174,11 +174,11 @@ void ImageItem::Reload(QString ImageFile
 
     image_file_name = ImageFile;
     QString pixtype = QString::fromLocal8Bit(image_data->getPixelType());
-    int16lprof = (pixtype.contains(QString::fromLocal8Bit("INT16")) > 0);
-    int32lprof = (pixtype.contains(QString::fromLocal8Bit("INT32")) > 0);
-    uint8lprof = (pixtype.contains(QString::fromLocal8Bit("UINT8")) > 0);
-    fltpixlprof = (pixtype.contains(QString::fromLocal8Bit("FLOAT")) > 0);
-    dblpixlprof = (pixtype.contains(QString::fromLocal8Bit("DOUBLE")) > 0);
+    int16lprof = pixtype.contains(QString::fromLocal8Bit("INT16"));
+    int32lprof = pixtype.contains(QString::fromLocal8Bit("INT32"));
+    uint8lprof = pixtype.contains(QString::fromLocal8Bit("UINT8"));
+    fltpixlprof = pixtype.contains(QString::fromLocal8Bit("FLOAT"));
+    dblpixlprof = pixtype.contains(QString::fromLocal8Bit("DOUBLE"));
 
     // try again
     vigra::DRGBImage in(image_data->width(), image_data->height());
