--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h.orig	2021-01-07 00:36:39 UTC
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h
@@ -45,9 +45,9 @@ class COMPONENT_EXPORT(
                                     mojom::RawOSMemDump*);
   static std::vector<mojom::VmRegionPtr> GetProcessMemoryMaps(base::ProcessId);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   static void SetProcSmapsForTesting(FILE*);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
  private:
   FRIEND_TEST_ALL_PREFIXES(OSMetricsTest, ParseProcSmaps);
@@ -61,7 +61,7 @@ class COMPONENT_EXPORT(
   static std::vector<mojom::VmRegionPtr> GetProcessModules(base::ProcessId);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   // Provides information on the dump state of resident pages. These values are
   // written to logs. New enum values can be added, but existing enums must
   // never be renumbered or deleted and reused.
@@ -96,7 +96,7 @@ class COMPONENT_EXPORT(
   // TODO(chiniforooshan): move to /base/process/process_metrics_linux.cc after
   // making sure that peak RSS is useful.
   static size_t GetPeakResidentSetSize(base::ProcessId pid);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 };
 
 }  // namespace memory_instrumentation
