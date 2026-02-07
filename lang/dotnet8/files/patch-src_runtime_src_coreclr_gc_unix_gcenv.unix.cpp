--- src/runtime/src/coreclr/gc/unix/gcenv.unix.cpp.orig	2023-11-01 21:55:24 UTC
+++ src/runtime/src/coreclr/gc/unix/gcenv.unix.cpp
@@ -1171,7 +1171,34 @@ uint64_t GetAvailablePhysicalMemory()
     uint64_t available = 0;
 
     // Get the physical memory available.
-#ifndef __APPLE__
+#if defined(__APPLE__)
+    vm_size_t page_size;
+    mach_port_t mach_port;
+    mach_msg_type_number_t count;
+    vm_statistics_data_t vm_stats;
+    mach_port = mach_host_self();
+    count = sizeof(vm_stats) / sizeof(natural_t);
+    if (KERN_SUCCESS == host_page_size(mach_port, &page_size))
+    {
+        if (KERN_SUCCESS == host_statistics(mach_port, HOST_VM_INFO, (host_info_t)&vm_stats, &count))
+        {
+            available = (int64_t)vm_stats.free_count * (int64_t)page_size;
+        }
+    }
+    mach_port_deallocate(mach_task_self(), mach_port);
+#elif defined(__FreeBSD__)
+    size_t inactive_count = 0, laundry_count = 0, free_count = 0;
+    size_t sz = sizeof(inactive_count);
+    sysctlbyname("vm.stats.vm.v_inactive_count", &inactive_count, &sz, NULL, 0); 
+
+    sz = sizeof(laundry_count);
+    sysctlbyname("vm.stats.vm.v_laundry_count", &laundry_count, &sz, NULL, 0); 
+
+    sz = sizeof(free_count);
+    sysctlbyname("vm.stats.vm.v_free_count", &free_count, &sz, NULL, 0);
+
+    available = (inactive_count + laundry_count + free_count) * sysconf(_SC_PAGESIZE);
+#else // Linux
     static volatile bool tryReadMemInfo = true;
 
     if (tryReadMemInfo)
@@ -1187,22 +1214,7 @@ uint64_t GetAvailablePhysicalMemory()
         // Fall back to getting the available pages using sysconf.
         available = sysconf(SYSCONF_PAGES) * sysconf(_SC_PAGE_SIZE);
     }
-#else // __APPLE__
-    vm_size_t page_size;
-    mach_port_t mach_port;
-    mach_msg_type_number_t count;
-    vm_statistics_data_t vm_stats;
-    mach_port = mach_host_self();
-    count = sizeof(vm_stats) / sizeof(natural_t);
-    if (KERN_SUCCESS == host_page_size(mach_port, &page_size))
-    {
-        if (KERN_SUCCESS == host_statistics(mach_port, HOST_VM_INFO, (host_info_t)&vm_stats, &count))
-        {
-            available = (int64_t)vm_stats.free_count * (int64_t)page_size;
-        }
-    }
-    mach_port_deallocate(mach_task_self(), mach_port);
-#endif // __APPLE__
+#endif
 
     return available;
 }
