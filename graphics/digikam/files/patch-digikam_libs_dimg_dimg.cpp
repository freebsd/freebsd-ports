--- digikam/libs/dimg/dimg.cpp.orig	2008-10-12 10:03:41.000000000 +0200
+++ digikam/libs/dimg/dimg.cpp	2008-10-12 10:07:25.000000000 +0200
@@ -42,7 +42,6 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
 #include <libkdcraw/kdcraw.h>
 
 // Local includes.
@@ -493,7 +492,7 @@
         return NONE;
     }
 
-    QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+    QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
     QString ext = fileInfo.extension(false).upper();
 
     if (!ext.isEmpty())
