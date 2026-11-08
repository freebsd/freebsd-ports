--- src/core/RS.cpp.orig	2026-08-26 20:00:19 UTC
+++ src/core/RS.cpp
@@ -176,6 +176,10 @@ QStringList RS::getDirectoryList(const QString& subDir
         appDir = fi.absolutePath();
     }
 
+#ifdef Q_OS_FREEBSD
+    dirList.append("%%DATADIR%%" + subDirectory);
+#endif
+
 #ifdef Q_OS_MAC
     // macOS app bundle:
     dirList.append(appDir + "/../Resources/" + subDirectory);
