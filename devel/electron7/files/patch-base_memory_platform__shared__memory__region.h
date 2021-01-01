--- base/memory/platform_shared_memory_region.h.orig	2019-12-12 12:38:59 UTC
+++ base/memory/platform_shared_memory_region.h
@@ -28,7 +28,7 @@
 #include "base/files/scoped_file.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace content {
 class SandboxIPCHandler;
 }
@@ -122,7 +122,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
     kMaxValue = GET_SHMEM_TEMP_DIR_FAILURE
   };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Structure to limit access to executable region creation.
   struct ExecutableRegion {
    private:
@@ -276,7 +276,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                            ,
                                            bool executable = false
 #endif
