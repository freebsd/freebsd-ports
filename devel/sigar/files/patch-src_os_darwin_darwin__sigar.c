--- src/os/darwin/darwin_sigar.c.orig	2014-11-17 21:46:20 UTC
+++ src/os/darwin/darwin_sigar.c
@@ -400,8 +400,10 @@ static int sigar_vmstat(sigar_t *sigar, 
     GET_VM_STATS(vm, v_inactive_target, 0);
     GET_VM_STATS(vm, v_inactive_count, 1);
     GET_VM_STATS(vm, v_cache_count, 1);
+#if (__FreeBSD_version < 1100079 )
     GET_VM_STATS(vm, v_cache_min, 0);
     GET_VM_STATS(vm, v_cache_max, 0);
+#endif
     GET_VM_STATS(vm, v_pageout_free_min, 0);
     GET_VM_STATS(vm, v_interrupt_free_min, 0);
     GET_VM_STATS(vm, v_forks, 0);
