--- ipc/ipc_channel_mojo.cc.orig	2025-08-26 20:49:50 UTC
+++ ipc/ipc_channel_mojo.cc
@@ -104,7 +104,7 @@ base::ProcessId GetSelfPID() {
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
