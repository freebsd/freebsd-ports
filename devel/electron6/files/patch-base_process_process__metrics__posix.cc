--- base/process/process_metrics_posix.cc.orig	2019-09-10 11:13:31 UTC
+++ base/process/process_metrics_posix.cc
@@ -19,6 +19,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_FREEBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -107,7 +109,7 @@ size_t ProcessMetrics::GetMallocUsage() {
 #else
   return minfo.hblkhd + minfo.arena;
 #endif
-#elif defined(OS_FUCHSIA)
+#elif defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
   return 0;
 #endif
