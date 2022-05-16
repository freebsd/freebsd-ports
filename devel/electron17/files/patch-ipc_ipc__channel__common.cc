--- ipc/ipc_channel_common.cc.orig	2022-05-11 07:16:53 UTC
+++ ipc/ipc_channel_common.cc
@@ -10,7 +10,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
