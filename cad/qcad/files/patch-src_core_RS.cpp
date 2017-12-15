--- src/core/RS.cpp.orig	2017-07-21 17:57:53 UTC
+++ src/core/RS.cpp
@@ -118,6 +118,10 @@ QStringList RS::getDirectoryList(const Q
     }
 
 #ifdef Q_OS_MAC
+#ifdef Q_OS_FREEBSD
+    dirList.append("%%DATADIR%%/" + subDirectory);
+#endif
+
     // Mac OS X app bundle:
     dirList.append(appDir + "/../Resources/" + subDirectory);
     dirList.append(appDir + "/../../../" + subDirectory);
