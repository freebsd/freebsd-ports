--- ./kipi-plugins/sendimages/sendimages.cpp.orig	2008-10-12 10:11:59.000000000 +0200
+++ ./kipi-plugins/sendimages/sendimages.cpp	2008-10-12 10:12:19.000000000 +0200
@@ -59,7 +59,6 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 #include <libkdcraw/kdcraw.h>
 
 // Local includes.
@@ -789,7 +788,7 @@
     QImage img;
 
     // Check if RAW file.
-    QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+    QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
     QFileInfo fileInfo(SourcePath);
     if (rawFilesExt.upper().contains( fileInfo.extension(false).upper() ))
         KDcrawIface::KDcraw::loadDcrawPreview(img, SourcePath);
