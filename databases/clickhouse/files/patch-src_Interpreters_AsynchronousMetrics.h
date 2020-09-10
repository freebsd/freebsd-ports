--- src/Interpreters/AsynchronousMetrics.h.orig	2020-08-31 16:22:57 UTC
+++ src/Interpreters/AsynchronousMetrics.h
@@ -50,7 +50,7 @@ class AsynchronousMetrics (private)
     bool quit {false};
     AsynchronousMetricValues values;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     MemoryStatisticsOS memory_stat;
 #endif
 
