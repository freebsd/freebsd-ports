--- content/browser/v8_snapshot_files.cc.orig	2022-05-11 07:16:51 UTC
+++ content/browser/v8_snapshot_files.cc
@@ -15,7 +15,7 @@ namespace content {
 
 std::map<std::string, base::FilePath> GetV8SnapshotFilesToPreload(
     base::CommandLine& process_command_line) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(USE_V8_CONTEXT_SNAPSHOT)
   return {{kV8ContextSnapshotDataDescriptor,
            base::FilePath(FILE_PATH_LITERAL(V8_CONTEXT_SNAPSHOT_FILENAME))}};
