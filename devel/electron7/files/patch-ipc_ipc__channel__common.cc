--- ipc/ipc_channel_common.cc.orig	2019-12-12 12:39:49 UTC
+++ ipc/ipc_channel_common.cc
@@ -9,7 +9,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
@@ -25,7 +25,7 @@ int Channel::GetGlobalPid() {
   return g_global_pid;
 }
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // static
 std::unique_ptr<Channel> Channel::CreateClient(
