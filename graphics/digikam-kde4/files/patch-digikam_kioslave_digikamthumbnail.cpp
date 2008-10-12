--- digikam/kioslave/digikamthumbnail.cpp.orig	2008-10-12 14:52:20.000000000 +0200
+++ digikam/kioslave/digikamthumbnail.cpp	2008-10-12 14:52:51.000000000 +0200
@@ -69,7 +69,6 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 #include <libkdcraw/kdcraw.h>
 
 // Local includes
@@ -264,7 +263,7 @@ bool kio_digikamthumbnailProtocol::loadB
         
     // Else, use the right way depending of image file extension.
     QString ext = fileInfo.extension(false).upper();
-    QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+    QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
 
     if (!ext.isEmpty())
     {
