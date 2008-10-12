--- digikam/digikam/albumsettings.cpp.orig	2008-10-12 15:02:59.000000000 +0200
+++ digikam/digikam/albumsettings.cpp	2008-10-12 15:03:20.000000000 +0200
@@ -36,7 +36,7 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -184,7 +184,7 @@ void AlbumSettings::init()
 
     // RAW files estentions supported by dcraw program and 
     // defines to digikam/libs/dcraw/rawfiles.h
-    d->defaultRawFilefilter         = QString(KDcrawIface::DcrawBinary::instance()->rawFiles());
+    d->defaultRawFilefilter         = QString(KDcrawIface::KDcraw::rawFiles());
 
     d->imageFilefilter              = d->defaultImageFilefilter;
     d->movieFilefilter              = d->defaultMovieFilefilter;
