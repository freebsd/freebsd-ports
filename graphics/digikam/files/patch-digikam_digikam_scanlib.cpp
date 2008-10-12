--- digikam/digikam/scanlib.cpp.orig	2008-07-16 21:05:55.000000000 +0200
+++ digikam/digikam/scanlib.cpp	2008-10-12 09:57:53.000000000 +0200
@@ -299,7 +299,7 @@
     int items = 0;
 
     QDir dir( directory );
-    if ( !dir.exists() or !dir.isReadable() )
+    if ( !dir.exists() || !dir.isReadable() )
         return 0;
 
     const QFileInfoList *list = dir.entryInfoList();
@@ -326,7 +326,7 @@
 void ScanLib::allFiles(const QString& directory)
 {
     QDir dir( directory );
-    if ( !dir.exists() or !dir.isReadable() )
+    if ( !dir.exists() || !dir.isReadable() )
     {
         DWarning() << "Folder does not exist or is not readable: "
                     << directory << endl;
