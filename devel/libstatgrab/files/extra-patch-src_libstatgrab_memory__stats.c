--- src/libstatgrab/memory_stats.c.orig	2019-01-21 17:51:57 UTC
+++ src/libstatgrab/memory_stats.c
@@ -323,10 +323,7 @@ sg_get_mem_stats_int(sg_mem_stats *mem_stats_buf) {
 		RETURN_WITH_SET_ERROR_WITH_ERRNO("mem", SG_ERROR_SYSCTLBYNAME, "vm.stats.vm.v_inactive_count");
 	}
 
-	size = sizeof(cache_count);
-	if (sysctlbyname("vm.stats.vm.v_cache_count", &cache_count, &size, NULL, 0) < 0) {
-		RETURN_WITH_SET_ERROR_WITH_ERRNO("mem", SG_ERROR_SYSCTLBYNAME, "vm.stats.vm.v_cache_count");
-	}
+	cache_count = 0;
 
 	/* Of couse nothing is ever that simple :) And I have inactive pages to
 	 * deal with too. So I'm going to add them to free memory :)
