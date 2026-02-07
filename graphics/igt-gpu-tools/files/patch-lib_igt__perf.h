--- lib/igt_perf.h.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_perf.h
@@ -27,10 +27,13 @@
 
 #include <stdint.h>
 
+#ifdef __linux__
 #include <linux/perf_event.h>
+#endif
 
 #include "igt_gt.h"
 
+#ifdef __linux__
 static inline int
 perf_event_open(struct perf_event_attr *attr,
 		pid_t pid,
@@ -50,6 +53,7 @@ perf_event_open(struct perf_event_attr *attr,
     attr->size = sizeof(*attr);
     return syscall(__NR_perf_event_open, attr, pid, cpu, group_fd, flags);
 }
+#endif /* __linux__ */
 
 uint64_t igt_perf_type_id(const char *device);
 int igt_perf_open(uint64_t type, uint64_t config);
