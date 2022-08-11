--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2022-05-19 05:17:34 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -32,7 +32,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
