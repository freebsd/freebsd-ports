--- remoting/host/ipc_constants.cc.orig	2022-05-11 07:16:54 UTC
+++ remoting/host/ipc_constants.cc
@@ -16,7 +16,7 @@ namespace remoting {
 
 namespace {
 
-#if !defined(NDEBUG) && defined(OS_LINUX)
+#if !defined(NDEBUG) && (defined(OS_LINUX) || defined(OS_BSD))
 // Use a different IPC name for Linux debug builds so that we can run the host
 // directly from out/Debug without interfering with the production host that
 // might also be running.
