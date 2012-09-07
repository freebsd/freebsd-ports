--- ipc/ipc_path_manager.cc.orig	2012-09-07 10:21:32.692021977 +0900
+++ ipc/ipc_path_manager.cc	2012-05-01 12:46:21.263693000 +0900
@@ -284,7 +284,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
