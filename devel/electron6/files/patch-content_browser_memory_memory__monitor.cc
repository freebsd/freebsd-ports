--- content/browser/memory/memory_monitor.cc.orig	2019-09-10 11:14:02 UTC
+++ content/browser/memory/memory_monitor.cc
@@ -22,7 +22,7 @@ void MemoryMonitorDelegate::GetSystemMemoryInfo(
   base::GetSystemMemoryInfo(mem_info);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // TODO(bashi,bcwhite): Remove when memory monitor for mac is available.
 std::unique_ptr<MemoryMonitor> CreateMemoryMonitor() {
   NOTREACHED();
