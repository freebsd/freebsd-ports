--- electron/shell/browser/api/process_metric.h.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/browser/api/process_metric.h
@@ -14,7 +14,7 @@
 
 namespace electron {
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 struct ProcessMemoryInfo {
   size_t working_set_size = 0;
   size_t peak_working_set_size = 0;
@@ -48,7 +48,7 @@ struct ProcessMetric {
                 const std::string& name = std::string());
   ~ProcessMetric();
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   ProcessMemoryInfo GetMemoryInfo() const;
 #endif
 
