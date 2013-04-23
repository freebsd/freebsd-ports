--- ipc/ipc_path_manager.cc.orig	2013-04-21 03:48:45.259273192 +0900
+++ ipc/ipc_path_manager.cc	2013-04-21 04:20:12.800269260 +0900
@@ -276,7 +276,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
