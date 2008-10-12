--- digikam/utilities/cameragui/cameraui.cpp.orig	2008-10-12 15:04:12.000000000 +0200
+++ digikam/utilities/cameragui/cameraui.cpp	2008-10-12 15:04:41.000000000 +0200
@@ -76,7 +76,7 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -944,14 +944,14 @@ void CameraUI::slotUpload()
     QString allPictures = patternList[0];
     
     // Add RAW file format to All Images" type mime and remplace current.
-    allPictures.insert(allPictures.find("|"), QString(KDcrawIface::DcrawBinary::instance()->rawFiles()));
+    allPictures.insert(allPictures.find("|"), QString(KDcrawIface::KDcraw::rawFiles()));
     patternList.remove(patternList[0]);
     patternList.prepend(allPictures);
     
     // Added RAW file formats supported by dcraw program like a type mime. 
     // Nota: we cannot use here "image/x-raw" type mime from KDE because it uncomplete 
     // or unavailable(dcraw_0)(see file #121242 in B.K.O).
-    patternList.append(QString("\n%1|Camera RAW files").arg(QString(KDcrawIface::DcrawBinary::instance()->rawFiles())));
+    patternList.append(QString("\n%1|Camera RAW files").arg(QString(KDcrawIface::KDcraw::rawFiles())));
     
     fileformats = patternList.join("\n");
 
