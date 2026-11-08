--- base/profiler/stack_sampling_profiler_test_util.cc.orig	2026-03-13 16:54:03 UTC
+++ base/profiler/stack_sampling_profiler_test_util.cc
@@ -46,7 +46,7 @@
 // Fortunately, it provides _alloca, which functions identically.
 #include <malloc.h>
 #define alloca _alloca
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
