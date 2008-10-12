--- digikam/libs/dialogs/imagedialog.cpp.orig	2008-10-12 14:50:22.000000000 +0200
+++ digikam/libs/dialogs/imagedialog.cpp	2008-10-12 14:51:29.000000000 +0200
@@ -39,7 +39,7 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -267,9 +267,8 @@ ImageDialog::ImageDialog(QWidget* parent
     QString allPictures = patternList[0];
 
     // Add other files format witch are missing to All Images" type mime provided by KDE and remplace current.
-    if (KDcrawIface::DcrawBinary::instance()->versionIsRight())
     {
-        allPictures.insert(allPictures.find("|"), QString(KDcrawIface::DcrawBinary::instance()->rawFiles()) + QString(" *.JPE *.TIF"));
+        allPictures.insert(allPictures.find("|"), QString(KDcrawIface::KDcraw::rawFiles()) + QString(" *.JPE *.TIF"));
         patternList.remove(patternList[0]);
         patternList.prepend(allPictures);
     }
@@ -277,9 +276,8 @@ ImageDialog::ImageDialog(QWidget* parent
     // Added RAW file formats supported by dcraw program like a type mime. 
     // Nota: we cannot use here "image/x-raw" type mime from KDE because it uncomplete 
     // or unavailable(dcraw_0)(see file #121242 in B.K.O).
-    if (KDcrawIface::DcrawBinary::instance()->versionIsRight())
     {
-        patternList.append(i18n("\n%1|Camera RAW files").arg(QString(KDcrawIface::DcrawBinary::instance()->rawFiles())));
+        patternList.append(i18n("\n%1|Camera RAW files").arg(QString(KDcrawIface::KDcraw::rawFiles())));
     }
 
     d->fileformats = patternList.join("\n");
