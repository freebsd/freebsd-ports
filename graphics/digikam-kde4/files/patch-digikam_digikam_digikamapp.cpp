--- digikam/digikam/digikamapp.cpp.orig	2008-10-12 14:53:14.000000000 +0200
+++ digikam/digikam/digikamapp.cpp	2008-10-12 14:55:23.000000000 +0200
@@ -62,7 +62,6 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 
 // Local includes.
 
@@ -163,7 +162,6 @@ DigikamApp::DigikamApp()
     if(d->splashScreen)
         d->splashScreen->message(i18n("Checking dcraw version"), AlignLeft, white);
 
-    KDcrawIface::DcrawBinary::instance()->checkSystem();
 
     if(d->splashScreen)
         d->splashScreen->message(i18n("Scan Albums"), AlignLeft, white);
@@ -221,7 +219,6 @@ DigikamApp::~DigikamApp()
 
     ImageAttributesWatch::cleanUp();
     LoadingCacheInterface::cleanUp();
-    KDcrawIface::DcrawBinary::cleanUp();
     AlbumThumbnailLoader::cleanUp();
 
     m_instance = 0;
@@ -276,7 +273,6 @@ void DigikamApp::show()
     }
 
     // Report errors from dcraw detection.
-    KDcrawIface::DcrawBinary::instance()->checkReport();
 
     // Init album icon view zoom factor. 
     slotThumbSizeChanged(d->albumSettings->getDefaultIconSize());
