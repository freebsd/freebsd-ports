--- lib/igt_perf.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_perf.c
@@ -4,13 +4,16 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/sysinfo.h>
 #include <sys/sysmacros.h>
+#endif
 #include <time.h>
 #include <unistd.h>
 
 #include "igt_perf.h"
 
+#ifdef __linux__
 static char *bus_address(int i915, char *path, int pathlen)
 {
 	struct stat st;
@@ -157,3 +160,58 @@ int igt_perf_open_group(uint64_t type, uint64_t config
 	return _perf_open(type, config, group,
 			  PERF_FORMAT_TOTAL_TIME_ENABLED | PERF_FORMAT_GROUP);
 }
+#elif defined(__FreeBSD__)
+uint64_t
+igt_perf_type_id(const char *device)
+{
+	return -ENOSYS;
+}
+
+int
+igt_perf_open(uint64_t type, uint64_t config)
+{
+	return -ENOSYS;
+}
+
+int
+igt_perf_open_group(uint64_t type, uint64_t config, int group)
+{
+	return -ENOSYS;
+}
+
+const char *
+i915_perf_device(int i915, char *buf, int buflen)
+{
+	return strerror(ENOSYS);
+}
+
+uint64_t
+i915_perf_type_id(int i915)
+{
+	return -ENOSYS;
+}
+
+int
+perf_igfx_open(uint64_t config)
+{
+	return -ENOSYS;
+}
+
+int
+perf_igfx_open_group(uint64_t config, int group)
+{
+	return -ENOSYS;
+}
+
+int
+perf_i915_open(int i915, uint64_t config)
+{
+	return -ENOSYS;
+}
+
+int
+perf_i915_open_group(int i915, uint64_t config, int group)
+{
+	return -ENOSYS;
+}
+#endif /* __linux__ */
