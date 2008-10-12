--- digikam/digikam/albumiconview.cpp.orig	2008-10-12 15:01:31.000000000 +0200
+++ digikam/digikam/albumiconview.cpp	2008-10-12 15:02:03.000000000 +0200
@@ -96,7 +96,6 @@ extern "C"
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 
 // Local includes.
 
@@ -1098,7 +1097,6 @@ void AlbumIconView::slotDisplayItem(Albu
     QString imagefilter = settings->getImageFileFilter().lower() +
                           settings->getImageFileFilter().upper();
 
-    if (KDcrawIface::DcrawBinary::instance()->versionIsRight())
     {
         // add raw files only if dcraw is available
         imagefilter += settings->getRawFileFilter().lower() +
