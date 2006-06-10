--- digikam/digikam/scanlib.cpp.orig	Tue Apr 11 13:48:55 2006
+++ digikam/digikam/scanlib.cpp	Tue Apr 11 13:50:28 2006
@@ -260,7 +260,7 @@
     int items = 0;
 
     QDir dir( directory );
-    if ( !dir.exists() or !dir.isReadable() )
+    if ( !dir.exists() || !dir.isReadable() )
         return 0;
 
     const QFileInfoList *list = dir.entryInfoList();
@@ -287,7 +287,7 @@
 void ScanLib::allFiles(const QString& directory)
 {
     QDir dir( directory );
-    if ( !dir.exists() or !dir.isReadable() )
+    if ( !dir.exists() || !dir.isReadable() )
     {
         kdWarning() << "Folder does not exist or is not readable: "
                     << directory << endl;
