--- tools/memory/partition_allocator/inspect_utils.h.orig	2022-06-17 14:20:10 UTC
+++ tools/memory/partition_allocator/inspect_utils.h
@@ -60,7 +60,7 @@ class RemoteProcessMemoryReader {
   const pid_t pid_;
   bool is_valid_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedFD mem_fd_;
 #elif BUILDFLAG(IS_MAC)
   task_t task_;
