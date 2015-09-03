--- build/src/baselayer.c.orig	2015-07-25 17:23:17 UTC
+++ build/src/baselayer.c
@@ -219,7 +219,7 @@ void calc_ylookup(int32_t bpl, int32_t l
     {
         Baligned_free(ylookup);
 
-        ylookup = (intptr_t *)Xaligned_alloc(16, lastyidx * sizeof(intptr_t));
+  	 posix_memalign(&ylookup, 16, lastyidx * sizeof(intptr_t));
 #if !defined(NOASM) && !defined(GEKKO) && !defined(__ANDROID__)
         nx_unprotect((intptr_t)ylookup, (intptr_t)ylookup + (lastyidx * sizeof(intptr_t)));
 #endif
