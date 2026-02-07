--- src/core/configmgr.cpp.orig	2024-08-06 13:56:46 UTC
+++ src/core/configmgr.cpp
@@ -576,7 +576,7 @@ void ConfigMgr::initAppPrefixPath()
     QStringList potential_dirs;
     auto app_dir_path = QCoreApplication::applicationDirPath();
     qInfo() << "app prefix path: " << app_dir_path;
-    potential_dirs << app_dir_path;
+    potential_dirs << app_dir_path << "%%DATADIR%%";
 
 #if defined(Q_OS_LINUX)
     QDir localBinDir(app_dir_path);
