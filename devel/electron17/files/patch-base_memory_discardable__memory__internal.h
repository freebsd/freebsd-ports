--- base/memory/discardable_memory_internal.h.orig	2022-05-11 07:16:46 UTC
+++ base/memory/discardable_memory_internal.h
@@ -10,7 +10,7 @@
 #include "base/metrics/field_trial_params.h"
 #include "build/build_config.h"
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace base {
 
