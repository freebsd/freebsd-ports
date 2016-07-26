--- src/soundsourceproxy.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/soundsourceproxy.cpp
@@ -84,7 +84,7 @@ void SoundSourceProxy::loadPlugins()
         qDebug() << "Adding plugin path from commandline arg:" << pluginPath;
         pluginDirs.append(QDir(pluginPath));
     }
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
     QDir libPath(UNIX_LIB_PATH);
     if (libPath.cd("plugins") && libPath.cd("soundsource")) {
 	pluginDirs.append(libPath.absolutePath());
