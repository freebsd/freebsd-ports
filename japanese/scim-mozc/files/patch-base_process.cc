--- base/process.cc	2010-08-13 19:48:06.000000000 +0900
+++ base/process.cc	2010-09-03 11:22:43.438900552 +0900
@@ -195,7 +195,7 @@
 #endif
 
 #ifdef OS_LINUX
-  static const char kBrowserCommand[] = "/usr/bin/xdg-open";
+  static const char kBrowserCommand[] = "@@LOCALBASE@@/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
