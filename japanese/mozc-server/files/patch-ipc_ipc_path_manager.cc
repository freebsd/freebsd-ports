--- ipc/ipc_path_manager.cc.orig	2011-12-24 13:17:13.114092857 +0900
+++ ipc/ipc_path_manager.cc	2011-12-04 16:46:51.134605388 +0900
@@ -274,7 +274,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
