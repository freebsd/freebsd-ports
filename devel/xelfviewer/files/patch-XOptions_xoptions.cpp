--- XOptions/xoptions.cpp.orig	2021-08-30 16:51:52 UTC
+++ XOptions/xoptions.cpp
@@ -742,7 +742,7 @@ QList<QString> XOptions::getAllFilesFromDirectory(QStr
 bool XOptions::checkNative()
 {
     bool bResult=false;
-#ifdef Q_OS_MAC
+#if defined(Q_OS_MAC) || defined(Q_OS_FREEBSD)
     bResult=true;
 #elif defined(Q_OS_LINUX)
     QString sApplicationDirPath=qApp->applicationDirPath();
@@ -792,6 +792,10 @@ QString XOptions::getApplicationDataPath()
     {
         sResult=sApplicationDirPath;
     }
+#elif defined(Q_OS_FREEBSD)
+    sResult = QStandardPaths::standardLocations(
+      QStandardPaths::GenericDataLocation).at(1)
+      + QDir::separator() + qApp->applicationName();
 #else
     sResult=sApplicationDirPath;
 #endif
