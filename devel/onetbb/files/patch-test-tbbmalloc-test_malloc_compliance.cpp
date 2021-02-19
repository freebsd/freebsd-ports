error: comparison of integers of different signs: 'size_t' (aka 'unsigned long') and 'rlim_t' (aka 'long')

--- test/tbbmalloc/test_malloc_compliance.cpp.orig	2020-12-08 11:00:57 UTC
+++ test/tbbmalloc/test_malloc_compliance.cpp
@@ -91,7 +91,7 @@ void limitMem( size_t limit )
     }
     if (rlim.rlim_max==(rlim_t)RLIM_INFINITY)
         rlim.rlim_cur = (limit > 0) ? limit*MByte : rlim.rlim_max;
-    else rlim.rlim_cur = (limit > 0 && limit<rlim.rlim_max) ? limit*MByte : rlim.rlim_max;
+    else rlim.rlim_cur = (limit > 0 && limit<(size_t)rlim.rlim_max) ? limit*MByte : rlim.rlim_max;
     ret = setrlimit(RLIMIT_AS,&rlim);
     if (0 != ret) {
         REPORT("Can't set limits: errno %d\n", errno);
