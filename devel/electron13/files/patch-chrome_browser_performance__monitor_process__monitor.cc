--- chrome/browser/performance_monitor/process_monitor.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/performance_monitor/process_monitor.cc
@@ -80,7 +80,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
                                     const ProcessMonitor::Metrics& rhs) {
   lhs.cpu_usage += rhs.cpu_usage;
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
