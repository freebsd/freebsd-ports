--- electron/shell/browser/api/process_metric.h.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/browser/api/process_metric.h
@@ -13,7 +13,7 @@
 
 namespace electron {
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 struct ProcessMemoryInfo {
   size_t working_set_size = 0;
   size_t peak_working_set_size = 0;
@@ -43,7 +43,7 @@ struct ProcessMetric {
                 std::unique_ptr<base::ProcessMetrics> metrics);
   ~ProcessMetric();
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   ProcessMemoryInfo GetMemoryInfo() const;
 #endif
 
