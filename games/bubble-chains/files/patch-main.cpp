--- main.cpp.orig	2020-12-22 07:59:21 UTC
+++ main.cpp
@@ -21,17 +21,7 @@ int main(int argc, char *argv[])
     QApplication a(argc, argv);
 
     // resources
-    QString resourcePath = a.applicationDirPath();
-    resourcePath.chop(3);
-    resourcePath += "data/"; // bin -> data
-
-    // on X11, we'll check if data directory exists locally first
-  #ifdef Q_OS_LINUX
-    qDebug() << resourcePath;
-
-    if (!QDir(resourcePath).exists())
-      resourcePath = "/usr/share/games/chains/data/";
-  #endif
+    QString resourcePath = "%%DATADIR%%/data/";
 
     if (!QDir(resourcePath).exists()) {
         QMessageBox::critical(nullptr, QString("Files are missing"),
