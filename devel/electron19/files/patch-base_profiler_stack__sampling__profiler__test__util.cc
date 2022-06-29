--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2022-05-25 04:00:43 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -39,7 +39,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
