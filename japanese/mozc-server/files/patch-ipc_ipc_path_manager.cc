--- ipc/ipc_path_manager.cc.orig	2012-04-02 08:17:58.917725634 +0900
+++ ipc/ipc_path_manager.cc	2012-04-02 08:38:43.523726676 +0900
@@ -272,7 +272,7 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) && !defined(__FreeBSD__)
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
