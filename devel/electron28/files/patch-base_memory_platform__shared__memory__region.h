--- base/memory/platform_shared_memory_region.h.orig	2023-08-10 01:48:30 UTC
+++ base/memory/platform_shared_memory_region.h
@@ -16,7 +16,7 @@
 
 #include <stdint.h>
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace content {
 class SandboxIPCHandler;
 }
@@ -83,7 +83,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
     kMaxValue = GET_SHMEM_TEMP_DIR_FAILURE
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Structure to limit access to executable region creation.
   struct ExecutableRegion {
    private:
@@ -215,7 +215,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                            ,
                                            bool executable = false
 #endif
