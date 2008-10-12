--- ./kipi-plugins/printwizard/tphoto.cpp.orig	2008-10-12 10:14:50.000000000 +0200
+++ ./kipi-plugins/printwizard/tphoto.cpp	2008-10-12 10:15:08.000000000 +0200
@@ -40,7 +40,6 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 #include <libkdcraw/kdcraw.h>
 
 
@@ -103,7 +102,7 @@
   QImage photo;
 
   // Check if RAW file.
-  QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+  QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
   QFileInfo fileInfo(filename.path());
   if (rawFilesExt.upper().contains( fileInfo.extension(false).upper() ))
     KDcrawIface::KDcraw::loadDcrawPreview(photo, filename.path());
