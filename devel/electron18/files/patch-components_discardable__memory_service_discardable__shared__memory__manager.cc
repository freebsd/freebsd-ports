--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2022-05-11 07:16:50 UTC
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -171,7 +171,7 @@ int64_t GetDefaultMemoryLimit() {
   // Limits the number of FDs used to 32, assuming a 4MB allocation size.
   int64_t max_default_memory_limit = 128 * kMegabyte;
 #else
-  int64_t max_default_memory_limit = 512 * kMegabyte;
+  int64_t max_default_memory_limit = 128 * kMegabyte;
 #endif
 
   // Use 1/8th of discardable memory on low-end devices.
