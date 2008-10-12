--- digikam/digikam/albumfiletip.cpp.orig	2008-10-12 15:02:22.000000000 +0200
+++ digikam/digikam/albumfiletip.cpp	2008-10-12 15:02:50.000000000 +0200
@@ -48,7 +48,7 @@
 
 // LibKDcraw includes. 
  
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
  
 // Local includes.
 
@@ -366,7 +366,7 @@ void AlbumFileTip::updateText()
         }
 
         QSize   dims;
-        QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+        QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
         QString ext = fileInfo.extension(false).upper();
 
         if (!ext.isEmpty() && rawFilesExt.upper().contains(ext))
