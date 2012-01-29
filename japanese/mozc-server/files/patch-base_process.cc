--- base/process.cc.orig	2012-01-29 13:42:31.198806477 +0900
+++ base/process.cc	2012-01-29 13:49:21.340806019 +0900
@@ -120,13 +120,18 @@
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
