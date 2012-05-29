--- ipc/ipc_path_manager.cc.orig	2012-05-29 15:37:10.807960643 +0900
+++ ipc/ipc_path_manager.cc	2012-05-01 12:46:21.263693646 +0900
@@ -284,7 +284,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
