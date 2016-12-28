--- qtxdg/xdgdirs.cpp.orig	2016-09-17 12:06:08 UTC
+++ qtxdg/xdgdirs.cpp
@@ -178,9 +178,11 @@ bool XdgDirs::setUserDir(XdgDirs::UserDi
     if (dir < XdgDirs::Desktop || dir > XdgDirs::Videos)
         return false;
 
+    const QString home = QFile::decodeName(qgetenv("HOME"));
     if (!(value.startsWith(QLatin1String("$HOME"))
                            || value.startsWith(QLatin1String("~/"))
-                           || value.startsWith(QFile::decodeName(qgetenv("HOME")))))
+                           || value.startsWith(home)
+                           || value.startsWith(QDir(home).canonicalPath())))
         return false;
 
     QString folderName = userDirectoryString[dir];
