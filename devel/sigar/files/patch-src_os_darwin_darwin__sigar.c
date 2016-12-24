--- src/os/darwin/darwin_sigar.c.orig	2014-11-17 21:46:20 UTC
+++ src/os/darwin/darwin_sigar.c
@@ -399,9 +399,13 @@ static int sigar_vmstat(sigar_t *sigar, 
     GET_VM_STATS(vm, v_active_count, 0);
     GET_VM_STATS(vm, v_inactive_target, 0);
     GET_VM_STATS(vm, v_inactive_count, 1);
+#if (__FreeBSD_version < 1200016 )
     GET_VM_STATS(vm, v_cache_count, 1);
+#endif
+#if (__FreeBSD_version < 1100079 )
     GET_VM_STATS(vm, v_cache_min, 0);
     GET_VM_STATS(vm, v_cache_max, 0);
+#endif
     GET_VM_STATS(vm, v_pageout_free_min, 0);
     GET_VM_STATS(vm, v_interrupt_free_min, 0);
     GET_VM_STATS(vm, v_forks, 0);
@@ -479,7 +483,11 @@ int sigar_mem_get(sigar_t *sigar, sigar_
     kern *= sigar->pagesize;
 #elif defined(__FreeBSD__)
     if ((status = sigar_vmstat(sigar, &vmstat)) == SIGAR_OK) {
+#if (__FreeBSD_version < 1200016 )
         kern = vmstat.v_cache_count + vmstat.v_inactive_count;
+#else
+        kern = vmstat.v_inactive_count;
+#endif
         kern *= sigar->pagesize;
         mem->free = vmstat.v_free_count;
         mem->free *= sigar->pagesize;
