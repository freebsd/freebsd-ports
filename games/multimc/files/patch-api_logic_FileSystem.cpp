--- api/logic/FileSystem.cpp.orig	2019-03-07 17:30:10 UTC
+++ api/logic/FileSystem.cpp
@@ -398,7 +398,7 @@ QString getDesktopDir()
 bool createShortCut(QString location, QString dest, QStringList args, QString name,
                           QString icon)
 {
-#if defined Q_OS_LINUX
+#if defined Q_OS_LINUX || defined(Q_OS_FREEBSD)
     location = PathCombine(location, name + ".desktop");
 
     QFile f(location);
