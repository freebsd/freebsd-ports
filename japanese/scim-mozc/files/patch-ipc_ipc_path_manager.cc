--- ipc/ipc_path_manager.cc.org	2010-09-25 11:09:39.543334634 +0900
+++ ipc/ipc_path_manager.cc	2010-09-25 11:10:01.975326409 +0900
@@ -265,7 +265,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
