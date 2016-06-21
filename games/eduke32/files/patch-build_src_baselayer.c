--- build/src/baselayer.c.orig	2016-05-29 21:11:27 UTC
+++ build/src/baselayer.c
@@ -227,7 +227,7 @@ void calc_ylookup(int32_t bpl, int32_t l
     {
         Baligned_free(ylookup);
 
-        ylookup = (intptr_t *)Xaligned_alloc(16, lastyidx * sizeof(intptr_t));
+	posix_memalign(&ylookup, 16, lastyidx * sizeof(intptr_t));
         ylookupsiz = lastyidx;
     }
 
