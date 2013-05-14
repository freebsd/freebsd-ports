--- base/process.cc.orig	2013-03-29 13:33:43.000000000 +0900
+++ base/process.cc	2013-04-24 00:17:03.000000000 +0900
@@ -122,7 +122,7 @@
 #endif
 
 #ifdef OS_LINUX
-  static const char kBrowserCommand[] = "/usr/bin/xdg-open";
+  static const char kBrowserCommand[] = LOCALBASE "/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
