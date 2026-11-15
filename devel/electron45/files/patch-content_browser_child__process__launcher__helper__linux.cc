--- content/browser/child_process_launcher_helper_linux.cc.orig	2026-10-30 11:54:04 UTC
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -23,7 +23,9 @@
 #include "content/public/common/content_switches.h"
 #include "content/public/common/result_codes.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/public/common/zygote/zygote_handle.h"
+#endif
 #include "sandbox/policy/linux/sandbox_linux.h"
 
 namespace content {
@@ -49,14 +51,20 @@ bool ChildProcessLauncherHelper::IsUsingLaunchOptions(
 }
 
 bool ChildProcessLauncherHelper::IsUsingLaunchOptions() {
+#if !BUILDFLAG(IS_BSD)
   return !GetZygoteForLaunch();
+#else
+  return true;
+#endif
 }
 
 bool ChildProcessLauncherHelper::BeforeLaunchOnLauncherThread(
     PosixFileDescriptorInfo& files_to_register,
     base::LaunchOptions* options) {
   if (options) {
+#if !BUILDFLAG(IS_BSD)
     CHECK(!GetZygoteForLaunch(), base::NotFatalUntil::M159);
+#endif
     // Convert FD mapping to FileHandleMappingVector
     options->fds_to_remap = files_to_register.GetMappingWithIDAdjustment(
         base::GlobalDescriptors::kBaseDescriptor);
@@ -71,6 +79,7 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
                                          remapped_fd.first);
     }
 
+#if !BUILDFLAG(IS_BSD)
     // (For Electron), if we're launching without zygote, that means we're
     // launching an unsandboxed process (since all sandboxed processes are
     // forked from the zygote). Relax the allow_new_privs option to permit
@@ -79,12 +88,15 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
         delegate_->GetZygote() == nullptr) {
       options->allow_new_privs = true;
     }
+#endif
 
     options->current_directory = delegate_->GetCurrentDirectory();
     options->environment = delegate_->GetEnvironment();
     options->clear_environment = !delegate_->ShouldInheritEnvironment();
   } else {
+#if !BUILDFLAG(IS_BSD)
     CHECK(GetZygoteForLaunch(), base::NotFatalUntil::M159);
+#endif
     // Environment variables could be supported in the future, but are not
     // currently supported when launching with the zygote.
     CHECK(delegate_->GetEnvironment().empty(), base::NotFatalUntil::M159);
@@ -101,6 +113,7 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
     int* launch_result) {
   *is_synchronous_launch = true;
   Process process;
+#if !BUILDFLAG(IS_BSD)
   ZygoteCommunication* zygote_handle = GetZygoteForLaunch();
   if (zygote_handle) {
     // TODO(crbug.com/40448989): If chrome supported multiple zygotes they could
@@ -111,7 +124,6 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !BUILDFLAG(IS_OPENBSD)
     if (handle) {
       // It could be a renderer process or an utility process.
       int oom_score = content::kMiscOomScore;
@@ -120,15 +132,17 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         oom_score = content::kLowestRendererOomScore;
       ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(handle, oom_score);
     }
-#endif
 
     process.process = base::Process(handle);
     process.zygote = zygote_handle;
   } else {
+#endif
     process.process = base::LaunchProcess(*command_line(), *options);
     *launch_result = process.process.IsValid() ? LAUNCH_RESULT_SUCCESS
                                                : LAUNCH_RESULT_FAILURE;
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS)
   process_id_ = process.process.Pid();
@@ -152,10 +166,14 @@ ChildProcessTerminationInfo ChildProcessLauncherHelper
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead) {
   ChildProcessTerminationInfo info;
+#if !BUILDFLAG(IS_BSD)
   if (process.zygote) {
     info.status = process.zygote->GetTerminationStatus(
         process.process.Handle(), known_dead, &info.exit_code);
   } else if (known_dead) {
+#else
+  if (known_dead) {
+#endif
     info.status = base::GetKnownDeadTerminationStatus(process.process.Handle(),
                                                       &info.exit_code);
   } else {
@@ -181,13 +199,17 @@ void ChildProcessLauncherHelper::ForceNormalProcessTer
   CHECK(CurrentlyOnProcessLauncherTaskRunner(), base::NotFatalUntil::M159);
   process.process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
+#if !BUILDFLAG(IS_BSD)
   if (process.zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     process.zygote->EnsureProcessTerminated(process.process.Handle());
   } else {
+#endif
     base::EnsureProcessTerminated(std::move(process.process));
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 }
 
 // static
@@ -200,11 +222,13 @@ void ChildProcessLauncherHelper::ApplyProcessPriorityO
   }
 }
 
+#if !BUILDFLAG(IS_BSD)
 ZygoteCommunication* ChildProcessLauncherHelper::GetZygoteForLaunch() {
   return base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
              ? nullptr
              : delegate_->GetZygote();
 }
+#endif
 
 base::File OpenFileToShare(const base::FilePath& path,
                            base::MemoryMappedFile::Region* region) {
