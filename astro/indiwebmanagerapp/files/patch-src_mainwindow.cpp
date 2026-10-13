--- src/mainwindow.cpp.orig	2026-09-20 18:12:07 UTC
+++ src/mainwindow.cpp
@@ -308,7 +308,7 @@ QString MainWindow::getDefault(QString option)
         if(!path.isEmpty())
             return path;
         // This is the user's python on many Linux Machines and Intel Macs.
-        path = checkForVersions("/usr/local/bin/python");
+        path = checkForVersions("%%LOCALBASE%%/bin/python3");
         if(!path.isEmpty())
             return path;
         // This is where python gets installed by Macs when installed from the Official Python Distribution
@@ -329,7 +329,7 @@ QString MainWindow::getDefault(QString option)
     // This is the location to set up the Virtual Environment for INDI Web Manager.  Many Computers today do not let you install packages like indi-web in the system python.
     else if (option == "INDIWebVENVPath")
     {
-        return QDir::homePath() + "/indiwebmanager";
+        return QDir::homePath() + "/.indiwebmanager";
     }
 
     //This is the Path to the GSC data folder.  It includes gsc at the end.
@@ -337,6 +337,8 @@ QString MainWindow::getDefault(QString option)
     {
     #ifdef Q_OS_MACOS
         return QStandardPaths::locate(QStandardPaths::GenericDataLocation, QString(), QStandardPaths::LocateDirectory) + "INDIWebManagerApp/gsc";
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/share/gsc";
     #endif
         if (flat.isEmpty() == false)
             return flat + "/share/GSC";
@@ -350,6 +352,8 @@ QString MainWindow::getDefault(QString option)
     #ifdef Q_OS_MACOS
         QString appPath = QCoreApplication::applicationDirPath();
         return QDir(appPath + "/../../").absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/bin";
     #endif
         return "";
     }
@@ -359,6 +363,8 @@ QString MainWindow::getDefault(QString option)
     {
     #ifdef Q_OS_MACOS
         return QDir(QCoreApplication::applicationDirPath()).absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/bin/";
     #endif
         if (flat.isEmpty() == false)
             return flat + "/bin/";
@@ -372,6 +378,8 @@ QString MainWindow::getDefault(QString option)
     #ifdef Q_OS_MACOS
         QString appPath = QCoreApplication::applicationDirPath();
         return QDir(appPath + "/../Resources/DriverSupport").absolutePath();
+    #elif defined(Q_OS_FREEBSD)
+        return "%%LOCALBASE%%/share/indi";
     #elif defined(Q_OS_LINUX)
         if (flat.isEmpty() == false)
             return flat + "/share/indi";
@@ -589,12 +597,12 @@ bool MainWindow::indiWebInstalled()
  */
 bool MainWindow::indiWebInstalled()
 {
-    return pathExists(Options::iNDIWebVENVPath() + "/bin/indi-web");
+    return pathExists("%%LOCALBASE%%/bin/indi-web");
 }
 
 bool MainWindow::indiWebVENVPathValid(QString indiWebVENVPath)
 {
-    return pathExists(indiWebVENVPath + "/bin/indi-web");
+    return pathExists("%%LOCALBASE%%/bin/indi-web");
 }
 
 /*
@@ -760,8 +768,8 @@ void MainWindow::startWebManager()
         processArguments << "--port" << Options::managerPortNumber();
     if(!Options::iNDIConfigPathDefault())
         processArguments << "--conf" << Options::iNDIConfigPath();
-    createManagerLogEntry(Options::iNDIWebVENVPath() + "/bin/indi-web" + " " + processArguments.join(" "));
-    webManager->start(Options::iNDIWebVENVPath() + "/bin/indi-web", processArguments);
+    createManagerLogEntry("%%LOCALBASE%%/bin/indi-web " + processArguments.join(" "));
+    webManager->start("%%LOCALBASE%%/bin/indi-web", processArguments);
     displayManagerStatusOnline(true);
 
     serverMonitor.start();
