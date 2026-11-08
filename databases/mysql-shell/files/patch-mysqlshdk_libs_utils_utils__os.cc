--- mysqlshdk/libs/utils/utils_os.cc.orig	2026-01-26 17:11:12 UTC
+++ mysqlshdk/libs/utils/utils_os.cc
@@ -37,7 +37,9 @@
 #include <pthread.h>
 #else
 #include <pthread.h>
+#ifndef __FreeBSD__
 #include <sys/sysinfo.h>
+#endif
 #include <sys/types.h>
 #endif
 
@@ -62,6 +64,8 @@ uint64_t available_memory() {
                                         (host_info64_t)&vm_stats, &count)) {
     return static_cast<uint64_t>(vm_stats.free_count) * page_size;
   }
+#elif __FreeBSD__
+  return 0;
 #else
   struct sysinfo info;
 
