--- components/power_metrics/energy_metrics_provider_linux.cc.orig	2024-02-15 09:02:48 UTC
+++ components/power_metrics/energy_metrics_provider_linux.cc
@@ -61,9 +61,9 @@ base::ScopedFD OpenPerfEvent(perf_event_attr* perf_att
 // value of less than 1. Here, we only consider cpu0. See details in
 // https://man7.org/linux/man-pages/man2/perf_event_open.2.html.
 base::ScopedFD OpenPerfEvent(perf_event_attr* perf_attr) {
-  base::ScopedFD perf_fd{syscall(__NR_perf_event_open, perf_attr, /*pid=*/-1,
+  base::ScopedFD perf_fd(syscall(__NR_perf_event_open, perf_attr, /*pid=*/-1,
                                  /*cpu=*/0, /*group_fd=*/-1,
-                                 PERF_FLAG_FD_CLOEXEC)};
+                                 static_cast<int>(PERF_FLAG_FD_CLOEXEC)));
   return perf_fd;
 }
 
