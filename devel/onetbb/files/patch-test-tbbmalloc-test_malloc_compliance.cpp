Backport b2b2a9d65b30b869962de8140a44f5b29a3072fd

--- test/tbbmalloc/test_malloc_compliance.cpp.orig	2021-06-30 08:19:55 UTC
+++ test/tbbmalloc/test_malloc_compliance.cpp
@@ -91,7 +91,7 @@ void limitMem( size_t limit )
     }
     if (rlim.rlim_max==(rlim_t)RLIM_INFINITY)
         rlim.rlim_cur = (limit > 0) ? limit*MByte : rlim.rlim_max;
-    else rlim.rlim_cur = (limit > 0 && limit<rlim.rlim_max) ? limit*MByte : rlim.rlim_max;
+    else rlim.rlim_cur = (limit > 0 && static_cast<rlim_t>(limit)<rlim.rlim_max) ? limit*MByte : rlim.rlim_max;
     ret = setrlimit(RLIMIT_AS,&rlim);
     if (0 != ret) {
         REPORT("Can't set limits: errno %d\n", errno);
