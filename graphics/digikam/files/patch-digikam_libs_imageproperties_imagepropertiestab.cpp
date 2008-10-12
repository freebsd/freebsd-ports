--- digikam/libs/imageproperties/imagepropertiestab.cpp.orig	2008-10-12 14:48:42.000000000 +0200
+++ digikam/libs/imageproperties/imagepropertiestab.cpp	2008-10-12 14:49:11.000000000 +0200
@@ -42,7 +42,7 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -424,7 +424,7 @@ void ImagePropertiesTab::setCurrentURL(c
 
     QSize   dims;
     QString compression, bitDepth, colorMode;
-    QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+    QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
     QString ext = fileInfo.extension(false).upper();
 
     if (!ext.isEmpty() && rawFilesExt.upper().contains(ext))
