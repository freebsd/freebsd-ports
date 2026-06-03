--- base/memory/platform_shared_memory_region_posix.cc.orig	2026-04-28 21:06:17 UTC
+++ base/memory/platform_shared_memory_region_posix.cc
@@ -171,7 +171,7 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                                               ,
                                                               bool executable
 #endif
@@ -196,7 +196,7 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
   // flag.
   FilePath directory;
   if (!GetShmemTempDir(
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           executable,
 #else
           false /* executable */,
