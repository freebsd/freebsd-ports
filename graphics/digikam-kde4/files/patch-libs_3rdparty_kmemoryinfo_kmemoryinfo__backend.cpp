--- libs/3rdparty/kmemoryinfo/kmemoryinfo_backend.cpp.orig	2015-02-26 18:08:01 UTC
+++ libs/3rdparty/kmemoryinfo/kmemoryinfo_backend.cpp
@@ -118,7 +118,7 @@ kvm_t* sg_get_kvm()
         return kvmd;
     }
 
-    kvmd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, NULL);
+    kvmd = kvm_openfiles(NULL, "/dev/null", NULL, O_RDONLY, NULL);
 
     if (kvmd == NULL)
     {
@@ -220,9 +220,9 @@ int get_mem_stats(Digikam::KMemoryInfo::
     int    mib[2];
     u_long physmem;
     size_t size;
-    u_long free_count;
-    u_long cache_count;
-    u_long inactive_count;
+    u_int free_count;
+    u_int cache_count;
+    u_int inactive_count;
     int    pagesize;
 #endif // defined(Q_OS_FREEBSD) || defined(Q_OS_DFBSD)
 
