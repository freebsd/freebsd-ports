--- storage/innobase/xtrabackup/src/utils.cc.orig	2025-06-26 11:44:12.347914000 +0300
+++ storage/innobase/xtrabackup/src/utils.cc	2025-06-26 11:47:31.087768000 +0300
@@ -19,16 +19,6 @@
 #include <my_default.h>
 #include <mysqld.h>
 
-#ifdef __APPLE__
-#include <mach/mach_host.h>
-#include <sys/sysctl.h>
-#else
-#ifdef HAVE_PROCPS_V3
-#include <proc/sysinfo.h>
-#else
-#include <libproc2/meminfo.h>
-#endif                                     // HAVE_PROCPS_V3
-#endif                                     // __APPLE__
 #include <boost/uuid/uuid.hpp>             // uuid class
 #include <boost/uuid/uuid_generators.hpp>  // generators
 #include <boost/uuid/uuid_io.hpp>          // streaming operators etc.
@@ -116,62 +106,13 @@
   return major * 10000 + minor * 100 + version;
 }
 
-#ifdef __APPLE__
 unsigned long host_total_memory() {
-  unsigned long total_mem = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
-  return total_mem;
+  return 0;
 }
 
 unsigned long host_free_memory() {
-  unsigned long total_mem = host_total_memory();
-  int64_t used_mem;
-  vm_size_t page_size;
-  mach_msg_type_number_t count;
-  vm_statistics_data_t vm_stats;
-
-  // Get used memory
-  mach_port_t host = mach_host_self();
-  count = sizeof(vm_stats) / sizeof(natural_t);
-  if (KERN_SUCCESS == host_page_size(host, &page_size) &&
-      KERN_SUCCESS ==
-          host_statistics(host, HOST_VM_INFO, (host_info_t)&vm_stats, &count)) {
-    used_mem = ((int64_t)vm_stats.active_count + (int64_t)vm_stats.wire_count) *
-               (int64_t)page_size;
-
-    ut_a(total_mem >= (unsigned long)used_mem);
-    return total_mem - (unsigned long)used_mem;
-  }
   return 0;
 }
-#else
-unsigned long host_total_memory() {
-#ifdef HAVE_PROCPS_V3
-  meminfo();
-  return kb_main_total * 1024;
-#else
-  struct meminfo_info *mem_info;
-  if (procps_meminfo_new(&mem_info) < 0) {
-    return 0;
-  }
-
-  return MEMINFO_GET(mem_info, MEMINFO_MEM_TOTAL, ul_int) * 1024;
-#endif  // HAVE_PROCPS_V3
-}
-
-unsigned long host_free_memory() {
-#ifdef HAVE_PROCPS_V3
-  meminfo();
-  return kb_main_available * 1024;
-#else
-  struct meminfo_info *mem_info;
-  if (procps_meminfo_new(&mem_info) < 0) {
-    return 0;
-  }
-
-  return MEMINFO_GET(mem_info, MEMINFO_MEM_AVAILABLE, ul_int) * 1024;
-#endif  // HAVE_PROCPS_V3
-}
-#endif
 
 std::string generate_uuid() {
   boost::uuids::uuid uuid = gen();
