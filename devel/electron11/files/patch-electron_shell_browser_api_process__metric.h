--- electron/shell/browser/api/process_metric.h.orig	2021-01-22 23:55:24 UTC
+++ electron/shell/browser/api/process_metric.h
@@ -14,7 +14,7 @@
 
 namespace electron {
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 struct ProcessMemoryInfo {
   size_t working_set_size = 0;
   size_t peak_working_set_size = 0;
@@ -46,7 +46,7 @@ struct ProcessMetric {
                 const std::string& name = std::string());
   ~ProcessMetric();
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   ProcessMemoryInfo GetMemoryInfo() const;
 #endif
 
