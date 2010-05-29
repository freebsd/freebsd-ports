--- src/base/process.cc.org	2010-05-29 12:46:19.289472417 +0900
+++ src/base/process.cc	2010-05-29 20:56:37.509543123 +0900
@@ -195,7 +195,7 @@
 #endif
 
 #ifdef OS_LINUX
-  static const char kBrowserCommand[] = "/usr/bin/xdg-open";
+  static const char kBrowserCommand[] = "@@LOCALBASE@@/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
