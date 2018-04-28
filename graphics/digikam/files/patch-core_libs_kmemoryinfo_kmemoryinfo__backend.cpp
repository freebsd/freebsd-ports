--- core/libs/kmemoryinfo/kmemoryinfo_backend.cpp.orig	2016-11-06 10:43:01 UTC
+++ core/libs/kmemoryinfo/kmemoryinfo_backend.cpp
@@ -117,7 +117,7 @@ kvm_t* sg_get_kvm()
         return kvmd;
     }
 
-    kvmd = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, NULL);
+    kvmd = kvm_openfiles(NULL, "/dev/null", NULL, O_RDONLY, NULL);
 
     if (kvmd == NULL)
     {
@@ -219,9 +219,9 @@ int get_mem_stats(Digikam::KMemoryInfo::
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
 
