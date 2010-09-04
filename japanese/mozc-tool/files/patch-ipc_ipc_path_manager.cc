--- ipc/ipc_path_manager.cc.org	2010-09-04 07:45:47.421394850 +0900
+++ ipc/ipc_path_manager.cc	2010-09-04 07:50:27.875266222 +0900
@@ -265,7 +265,10 @@
   *ipc_name = kIPCPrefix;
 #endif  // OS_WINDOWS
 
-#ifdef OS_LINUX
+#if !defined(__FreeBSD__) && defined(OS_LINUX)
+// XXX
+// Abstract Namespace of socket is LINUX ONLY incompatible feature.
+// XXX
   // On Linux, use abstract namespace which is independent of the file system.
   (*ipc_name)[0] = '\0';
 #endif
