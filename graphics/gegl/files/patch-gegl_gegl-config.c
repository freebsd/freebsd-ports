--- gegl/gegl-config.c.orig	2019-04-17 20:23:56 UTC
+++ gegl/gegl-config.c
@@ -34,6 +34,9 @@
 #include <unistd.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
 G_DEFINE_TYPE (GeglConfig, gegl_config, G_TYPE_OBJECT)
 
 static GObjectClass * parent_class = NULL;
@@ -219,8 +222,8 @@ gegl_config_class_init (GeglConfigClass *klass)
     long mem_total = default_tile_cache_size;
     long mem_min = 512 << 20; // 512mb
     long mem_available = mem_min;
+
 #ifdef G_OS_WIN32
-#ifdef G_OS_WIN32
 # if defined(_MSC_VER) && (_MSC_VER <= 1200)
   MEMORYSTATUS memory_status;
   memory_status.dwLength = sizeof (memory_status);
@@ -240,7 +243,46 @@ gegl_config_class_init (GeglConfigClass *klass)
     mem_available = memory_status.ullAvailPhys;
   }
 # endif
-#endif
+#elif defined(__APPLE__)
+    /* get total memory from the HW_MEMSIZE */
+    int64_t usermem;
+    size_t len = sizeof usermem;
+    static int mib[2] = { CTL_HW, HW_MEMSIZE };
+
+    if (sysctl (mib, 2, &usermem, &len, NULL, 0) == 0) {
+      mem_total = usermem;
+    }
+    /* and available mem from host_statistics64 */
+    vm_size_t              page_size = sysconf (_SC_PAGESIZE);
+    mach_port_t            host = mach_host_self ();
+    vm_statistics64_data_t vm_stat;
+    kern_return_t	         kret;
+    unsigned int           count = HOST_VM_INFO64_COUNT;
+
+    kret = host_statistics64 (host, HOST_VM_INFO64, (host_info64_t)&vm_stat, &count);
+
+    if (kret == KERN_SUCCESS)
+    {
+      mem_available = (long) (vm_stat.free_count + vm_stat.active_count
+                              + vm_stat.inactive_count
+# ifdef MAC_OS_X_VERSION_10_9
+                              + vm_stat.compressor_page_count
+# endif
+                             ) * page_size;
+      mach_port_deallocate (mach_task_self (), host);
+    }
+#elif defined(__FreeBSD__)
+
+    size_t len = sizeof(unsigned int);
+    unsigned int realmem, physmem;
+
+    if(sysctlbyname("hw.realmem", &realmem, &len, NULL, 0)) {
+      mem_total = (int64_t) realmem;
+    };
+
+    if (sysctlbyname("hw.physmem", &physmem, &len, NULL, 0)) {
+      mem_available = physmem;
+    }  
 
 #else
     mem_total = sysconf (_SC_PHYS_PAGES) * sysconf (_SC_PAGESIZE);
