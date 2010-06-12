--- base/process.cc.org	2010-06-11 18:01:03.000000000 +0900
+++ base/process.cc	2010-06-12 10:03:39.662872618 +0900
@@ -195,7 +195,7 @@
 #endif
 
 #ifdef OS_LINUX
-  static const char kBrowserCommand[] = "/usr/bin/xdg-open";
+  static const char kBrowserCommand[] = "@@LOCALBASE@@/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
