--- content/browser/v8_snapshot_files.cc.orig	2024-06-18 21:43:32 UTC
+++ content/browser/v8_snapshot_files.cc
@@ -17,7 +17,7 @@ GetV8SnapshotFilesToPreload(base::CommandLine& process
 std::map<std::string, absl::variant<base::FilePath, base::ScopedFD>>
 GetV8SnapshotFilesToPreload(base::CommandLine& process_command_line) {
   std::map<std::string, absl::variant<base::FilePath, base::ScopedFD>> files;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_V8_CONTEXT_SNAPSHOT)
   files[kV8ContextSnapshotDataDescriptor] = base::FilePath(
       FILE_PATH_LITERAL(BUILDFLAG(V8_CONTEXT_SNAPSHOT_FILENAME)));
