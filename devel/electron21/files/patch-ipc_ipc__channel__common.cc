--- ipc/ipc_channel_common.cc.orig	2022-05-19 14:06:27 UTC
+++ ipc/ipc_channel_common.cc
@@ -11,7 +11,7 @@
 
 namespace IPC {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 int g_global_pid = 0;
