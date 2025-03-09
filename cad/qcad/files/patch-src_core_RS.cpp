--- src/core/RS.cpp.orig	2025-02-10 09:29:49 UTC
+++ src/core/RS.cpp
@@ -174,6 +174,10 @@ QStringList RS::getDirectoryList(const QString& subDir
         appDir = fi.absolutePath();
     }
 
+#ifdef Q_OS_FREEBSD
+    dirList.append("/usr/local/share/qcad/" + subDirectory);
+#endif
+
 #ifdef Q_OS_MAC
     // macOS app bundle:
     dirList.append(appDir + "/../Resources/" + subDirectory);
