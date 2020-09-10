--- src/Interpreters/AsynchronousMetrics.cpp.orig	2020-08-31 16:22:57 UTC
+++ src/Interpreters/AsynchronousMetrics.cpp
@@ -194,7 +194,7 @@ void AsynchronousMetrics::update()
     new_values["Uptime"] = context.getUptimeSeconds();
 
     /// Process memory usage according to OS
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     {
         MemoryStatisticsOS::Data data = memory_stat.get();
 
