--- digikam/libs/thumbbar/thumbbar.cpp.orig	2008-10-12 14:49:37.000000000 +0200
+++ digikam/libs/thumbbar/thumbbar.cpp	2008-10-12 14:50:05.000000000 +0200
@@ -59,7 +59,7 @@ extern "C"
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -957,7 +957,7 @@ QString ThumbBarToolTip::tipContent(Thum
         }
 
         QSize   dims;
-        QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+        QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
         QString ext = fileInfo.extension(false).upper();
 
         if (!ext.isEmpty() && rawFilesExt.upper().contains(ext))
