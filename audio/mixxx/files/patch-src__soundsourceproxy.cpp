--- src/soundsourceproxy.cpp.orig	2011-12-24 11:53:20.000000000 +0900
+++ src/soundsourceproxy.cpp	2012-01-16 06:10:09.000000000 +0900
@@ -84,7 +84,7 @@
         qDebug() << "Adding plugin path from commandline arg:" << pluginPath;
         pluginDirs.append(QDir(pluginPath));
     }
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
     QDir libPath(UNIX_LIB_PATH);
     if (libPath.cd("plugins") && libPath.cd("soundsource")) {
 	pluginDirs.append(libPath.absolutePath());
