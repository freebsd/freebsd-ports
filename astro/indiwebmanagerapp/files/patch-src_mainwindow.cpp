--- src/mainwindow.cpp	2022-05-22 01:43:45.247103000 -0500
+++ src/mainwindow.cpp	2022-05-22 01:50:16.014480000 -0500
@@ -295,6 +295,8 @@
     #ifdef Q_OS_OSX
         //Note this is the Path where python3 gets symlinked by homebrew.
         return "/usr/local/opt/python/libexec/bin";
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/bin";
     #endif
         if (flat.isEmpty() == false)
             return flat + "/bin/";
@@ -307,6 +309,8 @@
     {
     #ifdef Q_OS_OSX
         return "/usr/local/bin/indi-web";
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/bin/indi-web";
     #endif
         return QDir::homePath() + "/.local/bin/indi-web";
     }
@@ -316,6 +320,8 @@
     {
     #ifdef Q_OS_OSX
         return QStandardPaths::locate(QStandardPaths::GenericDataLocation, QString(), QStandardPaths::LocateDirectory) + "INDIWebManagerApp/gsc";
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/share/gsc";
     #endif
         if (flat.isEmpty() == false)
             return flat + "/share/GSC";
@@ -329,6 +335,8 @@
     #ifdef Q_OS_OSX
         QString appPath = QCoreApplication::applicationDirPath();
         return QDir(appPath + "/../../").absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/bin/";
     #endif
         return "";
     }
@@ -338,6 +346,8 @@
     {
     #ifdef Q_OS_OSX
         return QDir(QCoreApplication::applicationDirPath()).absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/bin/";
     #endif
         if (flat.isEmpty() == false)
             return flat + "/bin/";
@@ -351,6 +361,8 @@
     #ifdef Q_OS_OSX
         QString appPath = QCoreApplication::applicationDirPath();
         return QDir(appPath + "/../Resources/DriverSupport").absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/share/indi";
     #elif defined(Q_OS_LINUX)
         if (flat.isEmpty() == false)
             return flat + "/share/indi";
@@ -543,7 +555,6 @@
  */
 bool MainWindow::pythonInstalled(QString pythonExecFolder)
 {
-
     return QFileInfo(pythonExecFolder + "/python").exists() || QFileInfo(pythonExecFolder + "/python2").exists() || QFileInfo(pythonExecFolder + "/python3").exists();
 }
 
