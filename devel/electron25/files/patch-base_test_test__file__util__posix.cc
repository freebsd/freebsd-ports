--- base/test/test_file_util_posix.cc.orig	2022-02-28 16:54:41 UTC
+++ base/test/test_file_util_posix.cc
@@ -88,7 +88,7 @@ void SyncPageCacheToDisk() {
 }
 
 #if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
