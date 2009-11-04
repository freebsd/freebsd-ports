--- src/Helper/mediadevicewatcher.cpp.orig	2009-11-04 22:48:51.000000000 +0100
+++ src/Helper/mediadevicewatcher.cpp	2009-11-04 22:50:13.000000000 +0100
@@ -73,6 +73,7 @@
             QString appExe = "Last.fm_debug";
         #endif
     #endif
+    QString appExe = "last.fm";
 
     QString app = QCoreApplication::applicationDirPath() + "/" + appExe;
     QStringList params( "-tray" );
