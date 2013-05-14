--- ipc/ipc_path_manager.cc.orig	2013-03-29 13:33:26.000000000 +0900
+++ ipc/ipc_path_manager.cc	2013-04-27 15:21:52.000000000 +0900
@@ -276,7 +276,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(OS_FREEBSD)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
