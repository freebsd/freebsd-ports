--- src/core/RS.cpp.orig	2019-05-01 14:25:33 UTC
+++ src/core/RS.cpp
@@ -146,6 +146,10 @@ QStringList RS::getDirectoryList(const QString& subDir
     }
 
 #ifdef Q_OS_MAC
+#ifdef Q_OS_FREEBSD
+    dirList.append("%%DATADIR%%/" + subDirectory);
+#endif
+
     // Mac OS X app bundle:
     dirList.append(appDir + "/../Resources/" + subDirectory);
     dirList.append(appDir + "/../../../" + subDirectory);
