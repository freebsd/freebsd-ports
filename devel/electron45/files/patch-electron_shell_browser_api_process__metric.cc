--- electron/shell/browser/api/process_metric.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/process_metric.cc
@@ -8,7 +8,7 @@
 #include <optional>
 #include <utility>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/string_split.h"
@@ -176,7 +176,7 @@ bool ProcessMetric::IsSandboxed() const {
 #endif
 }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 ProcessMemoryInfo ProcessMetric::GetMemoryInfo() const {
   ProcessMemoryInfo result;
