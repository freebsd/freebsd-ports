--- src/frontend/qt/fcitxwatcher.cpp.orig	2018-09-09 06:32:17 UTC
+++ src/frontend/qt/fcitxwatcher.cpp
@@ -24,6 +24,7 @@
 #include <QDir>
 #include <QFileSystemWatcher>
 #include <signal.h>
+#include <errno.h>
 
 // utils function in fcitx-utils and fcitx-config
 bool _pid_exists(pid_t pid) {
