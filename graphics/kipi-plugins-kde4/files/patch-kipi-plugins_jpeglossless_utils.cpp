--- ./kipi-plugins/jpeglossless/utils.cpp.orig	2008-10-12 10:10:46.000000000 +0200
+++ ./kipi-plugins/jpeglossless/utils.cpp	2008-10-12 10:11:24.000000000 +0200
@@ -57,7 +57,7 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -187,7 +187,7 @@
 
 bool Utils::isRAW(const QString& file)
 {
-    QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+    QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
 
     QFileInfo fileInfo(file);
     if (rawFilesExt.upper().contains( fileInfo.extension(false).upper() ))
