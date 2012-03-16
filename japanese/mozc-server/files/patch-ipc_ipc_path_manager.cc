--- ipc/ipc_path_manager.cc.orig	2012-03-16 10:48:02.136714319 +0900
+++ ipc/ipc_path_manager.cc	2012-03-16 10:59:56.379712949 +0900
@@ -274,7 +274,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
