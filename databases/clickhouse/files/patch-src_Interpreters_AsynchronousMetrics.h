--- src/Interpreters/AsynchronousMetrics.h.orig	2021-03-19 11:39:14 UTC
+++ src/Interpreters/AsynchronousMetrics.h
@@ -78,7 +78,7 @@ class AsynchronousMetrics (private)
     bool quit {false};
     AsynchronousMetricValues values;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     MemoryStatisticsOS memory_stat;
 #endif
 
