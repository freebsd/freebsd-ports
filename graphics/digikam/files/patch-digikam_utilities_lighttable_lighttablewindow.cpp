--- digikam/utilities/lighttable/lighttablewindow.cpp.orig	2008-10-12 15:03:34.000000000 +0200
+++ digikam/utilities/lighttable/lighttablewindow.cpp	2008-10-12 15:03:58.000000000 +0200
@@ -40,7 +40,6 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 
 // Local includes.
 
@@ -575,7 +574,6 @@ void LightTableWindow::loadImageInfos(co
     QString imagefilter = settings->getImageFileFilter().lower() +
                           settings->getImageFileFilter().upper();
 
-    if (KDcrawIface::DcrawBinary::instance()->versionIsRight())
     {
         // add raw files only if dcraw is available
         imagefilter += settings->getRawFileFilter().lower() +
