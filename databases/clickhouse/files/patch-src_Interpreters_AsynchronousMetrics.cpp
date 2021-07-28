--- src/Interpreters/AsynchronousMetrics.cpp.orig	2021-07-17 10:04:30 UTC
+++ src/Interpreters/AsynchronousMetrics.cpp
@@ -207,7 +207,7 @@ void AsynchronousMetrics::update()
     new_values["Uptime"] = getContext()->getUptimeSeconds();
 
     /// Process memory usage according to OS
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     {
         MemoryStatisticsOS::Data data = memory_stat.get();
 
