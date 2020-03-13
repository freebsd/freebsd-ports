--- base/memory/platform_shared_memory_region_posix.cc.orig	2019-12-12 12:38:59 UTC
+++ base/memory/platform_shared_memory_region_posix.cc
@@ -76,7 +76,7 @@ FDPair ScopedFDPair::get() const {
   return {fd.get(), readonly_fd.get()};
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 ScopedFD PlatformSharedMemoryRegion::ExecutableRegion::CreateFD(size_t size) {
   PlatformSharedMemoryRegion region =
@@ -85,7 +85,7 @@ ScopedFD PlatformSharedMemoryRegion::ExecutableRegion:
     return region.PassPlatformHandle().fd;
   return ScopedFD();
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Take(
@@ -224,7 +224,7 @@ bool PlatformSharedMemoryRegion::MapAtInternal(off_t o
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                                               ,
                                                               bool executable
 #endif
@@ -255,7 +255,7 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
   // flag.
   FilePath directory;
   if (!GetShmemTempDir(
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
           executable,
 #else
           false /* executable */,
