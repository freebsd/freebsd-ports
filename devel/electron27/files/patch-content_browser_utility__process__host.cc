--- content/browser/utility_process_host.cc.orig	2023-10-25 09:13:45 UTC
+++ content/browser/utility_process_host.cc
@@ -59,7 +59,7 @@
 #include "content/browser/v8_snapshot_files.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/pickle.h"
@@ -69,7 +69,7 @@
 #include "media/capture/capture_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "base/task/sequenced_task_runner.h"
 #include "components/viz/host/gpu_client.h"
 #include "media/capture/capture_switches.h"
@@ -80,7 +80,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 base::ScopedFD PassNetworkContextParentDirs(
     std::vector<base::FilePath> network_context_parent_dirs) {
   base::Pickle pickle;
@@ -129,7 +129,7 @@ UtilityProcessHost::UtilityProcessHost(std::unique_ptr
       started_(false),
       name_(u"utility process"),
       file_data_(std::make_unique<ChildProcessLauncherFileData>()),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       gpu_client_(nullptr, base::OnTaskRunnerDeleter(nullptr)),
 #endif
       client_(std::move(client)) {
@@ -438,7 +438,7 @@ bool UtilityProcessHost::StartProcess() {
     file_data_->files_to_preload.merge(GetV8SnapshotFilesToPreload());
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // The network service should have access to the parent directories
     // necessary for its usage.
     if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork) {
@@ -449,7 +449,7 @@ bool UtilityProcessHost::StartProcess() {
     }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Pass `kVideoCaptureUseGpuMemoryBuffer` flag to video capture service only
     // when the video capture use GPU memory buffer enabled and NV12 GPU memory
     // buffer supported.
