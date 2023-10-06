--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2022-08-31 12:19:35 UTC
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -171,7 +171,7 @@ uint64_t GetDefaultMemoryLimit() {
   // Limits the number of FDs used to 32, assuming a 4MB allocation size.
   uint64_t max_default_memory_limit = 128 * kMegabyte;
 #else
-  uint64_t max_default_memory_limit = 512 * kMegabyte;
+  uint64_t max_default_memory_limit = 128 * kMegabyte;
 #endif
 
   // Use 1/8th of discardable memory on low-end devices.
