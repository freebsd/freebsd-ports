--- src/core/RS.cpp.orig	2019-12-23 11:24:24 UTC
+++ src/core/RS.cpp
@@ -145,6 +145,10 @@ QStringList RS::getDirectoryList(const QString& subDir
         appDir = fi.absolutePath();
     }
 
+#ifdef Q_OS_FREEBSD
+    dirList.append("%%DATADIR%%/" + subDirectory);
+#endif
+
 #ifdef Q_OS_MAC
     // Mac OS X app bundle:
     dirList.append(appDir + "/../Resources/" + subDirectory);
