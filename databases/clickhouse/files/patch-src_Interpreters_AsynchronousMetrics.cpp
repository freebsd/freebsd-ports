--- src/Interpreters/AsynchronousMetrics.cpp.orig	2021-03-19 11:39:14 UTC
+++ src/Interpreters/AsynchronousMetrics.cpp
@@ -196,7 +196,7 @@ void AsynchronousMetrics::update()
     new_values["Uptime"] = global_context.getUptimeSeconds();
 
     /// Process memory usage according to OS
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     {
         MemoryStatisticsOS::Data data = memory_stat.get();
 
