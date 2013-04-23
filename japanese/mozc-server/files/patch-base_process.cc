--- base/process.cc.orig	2013-04-21 03:48:45.176269982 +0900
+++ base/process.cc	2013-04-21 04:16:40.382269441 +0900
@@ -121,13 +121,18 @@
   return ShellExecuteInSystemDir(L"open", wurl.c_str(), NULL, SW_SHOW);
 #endif
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   static const char kBrowserCommand[] = "/usr/bin/xdg-open";
   // xdg-open which uses kfmclient or gnome-open internally works both on KDE
   // and GNOME environments.
   return SpawnProcess(kBrowserCommand, url);
 #endif  // LINUX
 
+#ifdef __FreeBSD__
+  static const char kBrowserCommand[] = "@@LOCALBASE@@/bin/xdg-open";
+  return SpawnProcess(kBrowserCommand, url);
+#endif
+
 #ifdef OS_MACOSX
   return MacProcess::OpenBrowserForMac(url);
 #endif  // OS_MACOSX
