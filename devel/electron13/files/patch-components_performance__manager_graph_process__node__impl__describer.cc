--- components/performance_manager/graph/process_node_impl_describer.cc.orig	2021-07-15 19:13:37 UTC
+++ components/performance_manager/graph/process_node_impl_describer.cc
@@ -58,7 +58,7 @@ base::Value GetProcessValueDict(const base::Process& p
   if (process.IsValid()) {
     // These properties can only be accessed for valid processes.
     ret.SetIntKey("os_priority", process.GetPriority());
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
     ret.SetBoolKey("is_backgrounded", process.IsProcessBackgrounded());
 #endif
 #if !defined(OS_ANDROID) && !defined(OS_WIN)
