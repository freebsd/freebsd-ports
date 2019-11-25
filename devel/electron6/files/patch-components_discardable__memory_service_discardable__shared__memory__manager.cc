--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2019-09-10 11:13:51 UTC
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -32,7 +32,7 @@
 #include "components/discardable_memory/common/discardable_shared_memory_heap.h"
 #include "mojo/public/cpp/bindings/strong_binding.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/file_path.h"
 #include "base/files/file_util.h"
 #include "base/metrics/histogram_macros.h"
@@ -170,7 +170,7 @@ int64_t GetDefaultMemoryLimit() {
     max_default_memory_limit /= 8;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath shmem_dir;
   if (base::GetShmemTempDir(false, &shmem_dir)) {
     int64_t shmem_dir_amount_of_free_space =
