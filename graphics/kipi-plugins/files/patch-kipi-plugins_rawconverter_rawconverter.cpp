--- ./kipi-plugins/rawconverter/plugin_rawconverter.cpp.orig	2008-10-12 10:15:43.000000000 +0200
+++ ./kipi-plugins/rawconverter/plugin_rawconverter.cpp	2008-10-12 10:18:27.000000000 +0200
@@ -53,7 +53,7 @@
 
 // LibKDcraw includes.
 
-#include <libkdcraw/dcrawbinary.h>
+#include <libkdcraw/kdcraw.h>
 
 // Local includes.
 
@@ -116,7 +116,7 @@
 
 bool Plugin_RawConverter::isRAWFile(const QString& filePath)
 {
-    QString rawFilesExt(KDcrawIface::DcrawBinary::instance()->rawFiles());
+    QString rawFilesExt(KDcrawIface::KDcraw::rawFiles());
 
     QFileInfo fileInfo(filePath);
     if (rawFilesExt.upper().contains( fileInfo.extension(false).upper() ))
@@ -127,9 +127,7 @@
 
 bool Plugin_RawConverter::checkBinaries()
 {
-    KDcrawIface::DcrawBinary::instance()->checkSystem();
-    KDcrawIface::DcrawBinary::instance()->checkReport();
-    return KDcrawIface::DcrawBinary::instance()->isAvailable();
+    return true;
 }
 
 void Plugin_RawConverter::slotActivateSingle()
