--- chrome/updater/device_management/dm_storage.cc.orig	2022-05-19 03:45:22 UTC
+++ chrome/updater/device_management/dm_storage.cc
@@ -70,7 +70,7 @@ bool DeleteObsoletePolicies(const base::FilePath& cach
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // crbug.com/1276162 - implement.
 DMStorage::DMStorage(const base::FilePath& policy_cache_root)
     : policy_cache_root_(policy_cache_root) {
