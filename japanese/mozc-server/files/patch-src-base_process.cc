--- src/base/process.cc.orig	2016-03-13 11:22:55.000000000 +0900
+++ src/base/process.cc	2016-05-10 21:54:57.488770000 +0900
@@ -126,7 +126,7 @@
 #endif
 
 #if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
-  static const char kBrowserCommand[] = "/usr/bin/xdg-open";
+  static const char kBrowserCommand[] = LOCALBASE "/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
