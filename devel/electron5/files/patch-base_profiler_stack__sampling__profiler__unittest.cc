--- base/profiler/stack_sampling_profiler_unittest.cc.orig	2019-04-08 08:32:37 UTC
+++ base/profiler/stack_sampling_profiler_unittest.cc
@@ -39,7 +39,7 @@
 #include <intrin.h>
 #include <malloc.h>
 #include <windows.h>
-#else
+#elif !defined(OS_BSD)
 #include <alloca.h>
 #endif
 
