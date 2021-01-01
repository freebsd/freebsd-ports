--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2019-12-12 12:38:59 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -41,7 +41,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
