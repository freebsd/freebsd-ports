--- ipc/ipc_channel_common.cc.orig	2019-03-15 06:25:46 UTC
+++ ipc/ipc_channel_common.cc
@@ -9,7 +9,7 @@
 
 namespace IPC {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 int g_global_pid = 0;
