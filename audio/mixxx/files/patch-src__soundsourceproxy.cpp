--- src/soundsourceproxy.cpp.orig	2011-12-24 11:53:20.000000000 +0900
+++ src/soundsourceproxy.cpp	2012-01-16 06:10:09.000000000 +0900
@@ -80,7 +80,10 @@
         qDebug() << "Adding plugin path from commandline arg:" << clArgs.at(pluginPath + 1);
         pluginDirs.append(QDir(clArgs.at(pluginPath + 1)));
     }
-#ifdef __LINUX__
+#ifdef __BSD__
+    pluginDirs.append(QDir("%%PREFIX%%/lib/mixxx/plugins/soundsource/"));
+    pluginDirs.append(QDir(QDesktopServices::storageLocation(QDesktopServices::HomeLocation) + "/.mixxx/plugins/soundsource/"));
+#elif __LINUX__
     pluginDirs.append(QDir("/usr/local/lib/mixxx/plugins/soundsource/"));
     pluginDirs.append(QDir("/usr/lib/mixxx/plugins/soundsource/"));
     pluginDirs.append(QDir(QDesktopServices::storageLocation(QDesktopServices::HomeLocation) + "/.mixxx/plugins/soundsource/"));
