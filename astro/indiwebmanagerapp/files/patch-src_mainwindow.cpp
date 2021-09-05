--- src/mainwindow.cpp	2021-09-04 23:55:40.427687000 -0500
+++ src/mainwindow.cpp	2021-09-05 00:10:09.774435000 -0500
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
@@ -339,6 +345,8 @@
     #ifdef Q_OS_OSX
         QString appPath = QCoreApplication::applicationDirPath();
         return QDir(appPath + "/indi").absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/bin/";
     #endif
         if (flat.isEmpty() == false)
             return flat + "/bin/";
@@ -352,6 +360,8 @@
     #ifdef Q_OS_OSX
         QString appPath = QCoreApplication::applicationDirPath();
         return QDir(appPath + "/../Resources/DriverSupport").absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/share/indi";
     #elif defined(Q_OS_LINUX)
         if (flat.isEmpty() == false)
             return flat + "/share/indi";
@@ -544,7 +554,6 @@
  */
 bool MainWindow::pythonInstalled(QString pythonExecFolder)
 {
-
     return QFileInfo(pythonExecFolder + "/python").exists() || QFileInfo(pythonExecFolder + "/python2").exists() || QFileInfo(pythonExecFolder + "/python3").exists();
 }
 
