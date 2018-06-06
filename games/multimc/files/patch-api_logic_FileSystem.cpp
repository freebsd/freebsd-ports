--- api/logic/FileSystem.cpp.orig	2017-12-18 00:19:43 UTC
+++ api/logic/FileSystem.cpp
@@ -407,7 +407,7 @@ QString getDesktopDir()
 bool createShortCut(QString location, QString dest, QStringList args, QString name,
 						  QString icon)
 {
-#if defined Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	location = PathCombine(location, name + ".desktop");
 
 	QFile f(location);
