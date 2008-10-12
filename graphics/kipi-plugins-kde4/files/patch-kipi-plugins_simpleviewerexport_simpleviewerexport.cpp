--- ./kipi-plugins/simpleviewerexport/simpleviewerexport.cpp.orig	2008-10-12 10:13:11.000000000 +0200
+++ ./kipi-plugins/simpleviewerexport/simpleviewerexport.cpp	2008-10-12 10:13:42.000000000 +0200
@@ -52,7 +52,6 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 #include <libkdcraw/kdcraw.h>
 
 // LibKExiv2 includes.
@@ -376,7 +375,7 @@
             m_progressDlg->addedAction(i18n("Processing %1").arg(url.filename()), KIPI::StartingMessage);
 
             // Check if RAW file.
-            QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+            QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
             if (rawFilesExt.upper().contains( fileInfo.extension(false).upper() ))
                 KDcrawIface::KDcraw::loadDcrawPreview(image, url.path());
             else
