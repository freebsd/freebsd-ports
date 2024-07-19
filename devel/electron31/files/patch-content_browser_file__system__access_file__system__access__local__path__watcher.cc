--- content/browser/file_system_access/file_system_access_local_path_watcher.cc.orig	2024-06-18 21:43:31 UTC
+++ content/browser/file_system_access/file_system_access_local_path_watcher.cc
@@ -64,7 +64,7 @@ void FileSystemAccessLocalPathWatcher::Initialize(
       .type = scope().IsRecursive()
                   ? base::FilePathWatcher::Type::kRecursive
                   : base::FilePathWatcher::Type::kNonRecursive,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Note: `report_modified_path` is also present on Android
       // and Fuchsia. Update this switch if support for watching
       // the local file system is added on those platforms.
