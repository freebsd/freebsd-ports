--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2023-02-01 18:43:07 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -33,7 +33,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
