--- digikam/kioslave/digikamalbums.cpp.orig	2008-10-12 14:51:40.000000000 +0200
+++ digikam/kioslave/digikamalbums.cpp	2008-10-12 14:52:08.000000000 +0200
@@ -72,7 +72,7 @@ extern "C" 
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -269,7 +269,7 @@ void kio_digikamalbums::special(const QB
                 if (getDimensions)
                 {
                     QFileInfo fileInfo(base + name);
-                    QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+                    QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
                     QString ext = fileInfo.extension(false).upper();
     
                     if (!ext.isEmpty() && rawFilesExt.upper().contains(ext))
