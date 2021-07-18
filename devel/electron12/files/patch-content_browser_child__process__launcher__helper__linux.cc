--- content/browser/child_process_launcher_helper_linux.cc.orig	2021-01-25 11:27:00 UTC
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -18,9 +18,12 @@
 #include "content/public/common/content_switches.h"
 #include "content/public/common/result_codes.h"
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
+
+#if !defined(OS_BSD)
 #include "content/public/common/zygote/sandbox_support_linux.h"
 #include "content/public/common/zygote/zygote_handle.h"
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace content {
 namespace internal {
@@ -50,6 +53,7 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
   options->fds_to_remap = files_to_register.GetMappingWithIDAdjustment(
       base::GlobalDescriptors::kBaseDescriptor);
 
+#if !defined(OS_BSD)
   if (GetProcessType() == switches::kRendererProcess) {
     const int sandbox_fd = SandboxHostLinux::GetInstance()->GetChildSocket();
     options->fds_to_remap.push_back(std::make_pair(sandbox_fd, GetSandboxFD()));
@@ -66,6 +70,7 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
       options->allow_new_privs = true;
     }
   }
+#endif
 
   options->environment = delegate_->GetEnvironment();
 
@@ -80,6 +85,7 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -109,6 +115,7 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
     process.zygote = zygote_handle;
     return process;
   }
+#endif
 
   Process process;
   process.process = base::LaunchProcess(*command_line(), options);
@@ -126,10 +133,14 @@ ChildProcessTerminationInfo ChildProcessLauncherHelper
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead) {
   ChildProcessTerminationInfo info;
+#if !defined(OS_BSD)
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
@@ -153,13 +164,17 @@ void ChildProcessLauncherHelper::ForceNormalProcessTer
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
   process.process.Terminate(RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
+#if !defined(OS_BSD)
   if (process.zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     process.zygote->EnsureProcessTerminated(process.process.Handle());
   } else {
+#endif
     base::EnsureProcessTerminated(std::move(process.process));
+#if !defined(OS_BSD)
   }
+#endif
 }
 
 void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(
