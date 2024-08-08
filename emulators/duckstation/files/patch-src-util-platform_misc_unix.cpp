--- src/util/platform_misc_unix.cpp.orig	2024-06-14 05:59:32 UTC
+++ src/util/platform_misc_unix.cpp
@@ -134,6 +134,7 @@ size_t PlatformMisc::GetRuntimeCacheLineSize()
 
 size_t PlatformMisc::GetRuntimeCacheLineSize()
 {
+#if defined(__linux__)
   int l1i = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
   int l1d = sysconf(_SC_LEVEL1_ICACHE_LINESIZE);
   int res = (l1i > l1d) ? l1i : l1d;
@@ -152,6 +153,9 @@ size_t PlatformMisc::GetRuntimeCacheLineSize()
   }
 
   return (res > 0) ? static_cast<size_t>(res) : 0;
+#else
+  return HOST_CACHE_LINE_SIZE;
+#endif
 }
 
 bool PlatformMisc::PlaySoundAsync(const char* path)
