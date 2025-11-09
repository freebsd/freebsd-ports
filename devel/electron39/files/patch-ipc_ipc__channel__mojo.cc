--- ipc/ipc_channel_mojo.cc.orig	2025-10-21 20:19:54 UTC
+++ ipc/ipc_channel_mojo.cc
@@ -72,7 +72,7 @@ base::ProcessId GetSelfPID() {
 };
 
 base::ProcessId GetSelfPID() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (int global_pid = Channel::GetGlobalPid())
     return global_pid;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
