--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2022-05-19 05:17:34 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -41,7 +41,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <alloca.h>
 #endif
 
