--- electron/shell/browser/api/process_metric.h.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/api/process_metric.h
@@ -14,7 +14,7 @@
 
 namespace electron {
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 struct ProcessMemoryInfo {
   size_t working_set_size = 0;
   size_t peak_working_set_size = 0;
@@ -48,7 +48,7 @@ struct ProcessMetric {
                 const std::string& name = std::string());
   ~ProcessMetric();
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   ProcessMemoryInfo GetMemoryInfo() const;
 #endif
 
