--- content/app/content_main_runner_impl.cc.orig	2025-09-10 14:33:47 UTC
+++ content/app/content_main_runner_impl.cc
@@ -150,18 +150,20 @@
 #include "content/browser/posix_file_descriptor_info_impl.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 #include "content/public/common/zygote/zygote_fork_delegate_linux.h"
 #endif
 
 #endif  // BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/file_path_watcher_inotify.h"
 #include "base/native_library.h"
 #include "base/rand_util.h"
 #include "content/public/common/zygote/sandbox_support_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "third_party/boringssl/src/include/openssl/crypto.h"
 #include "third_party/webrtc_overrides/init_webrtc.h"  // nogncheck
 
@@ -185,6 +187,10 @@
 #include "media/base/media_switches.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/system/sys_info.h"
+#endif
+
 #if BUILDFLAG(IS_ANDROID)
 #include "base/system/sys_info.h"
 #include "content/browser/android/battery_metrics.h"
@@ -384,7 +390,7 @@ void InitializeZygoteSandboxForBrowserProcess(
 }
 #endif  // BUILDFLAG(USE_ZYGOTE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(ENABLE_LIBRARY_CDMS)
 // Loads registered library CDMs but does not initialize them. This is needed by
@@ -403,7 +409,10 @@ void PreSandboxInit() {
 
 void PreSandboxInit() {
   // Ensure the /dev/urandom is opened.
+  // we use arc4random
+#if !BUILDFLAG(IS_BSD)
   base::GetUrandomFD();
+#endif
 
   // May use sysinfo(), sched_getaffinity(), and open various /sys/ and /proc/
   // files.
@@ -415,9 +424,16 @@ void PreSandboxInit() {
   // https://boringssl.googlesource.com/boringssl/+/HEAD/SANDBOXING.md
   CRYPTO_pre_sandbox_init();
 
+#if BUILDFLAG(IS_BSD)
+  // "cache" the amount of physical memory before pledge(2)
+  base::SysInfo::AmountOfPhysicalMemoryMB();
+#endif
+
+#if !BUILDFLAG(IS_BSD)
   // Pre-read /proc/sys/fs/inotify/max_user_watches so it doesn't have to be
   // allowed by the sandbox.
   base::GetMaxNumberOfInotifyWatches();
+#endif
 
 #if BUILDFLAG(ENABLE_LIBRARY_CDMS)
   // Ensure access to the library CDMs before the sandbox is turned on.
@@ -637,7 +653,7 @@ NO_STACK_PROTECTOR int RunZygote(ContentMainDelegate* 
 
   // Once Zygote forks and feature list initializes we can start a thread to
   // begin tracing immediately.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (process_type == switches::kGpuProcess) {
     tracing::InitTracingPostFeatureList(/*enable_consumer=*/false,
                                         /*will_trace_thread_restart=*/true);
@@ -736,7 +752,7 @@ NO_STACK_PROTECTOR int RunOtherNamedProcessTypeMain(
     base::HangWatcher::CreateHangWatcherInstance();
     unregister_thread_closure = base::HangWatcher::RegisterThread(
         base::HangWatcher::ThreadType::kMainThread);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On Linux/ChromeOS, the HangWatcher can't start until after the sandbox is
     // initialized, because the sandbox can't be started with multiple threads.
     // TODO(mpdenton): start the HangWatcher after the sandbox is initialized.
@@ -854,11 +870,10 @@ int ContentMainRunnerImpl::Initialize(ContentMainParam
                  base::GlobalDescriptors::kBaseDescriptor);
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   g_fds->Set(kCrashDumpSignal,
              kCrashDumpSignal + base::GlobalDescriptors::kBaseDescriptor);
-#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_OPENBSD)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 #endif  // !BUILDFLAG(IS_WIN)
 
@@ -1010,7 +1025,7 @@ int ContentMainRunnerImpl::Initialize(ContentMainParam
     // SeatbeltExecServer.
     CHECK(sandbox::Seatbelt::IsSandboxed());
   }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // In sandboxed processes and zygotes, certain resource should be pre-warmed
   // as they cannot be initialized under a sandbox. In addition, loading these
   // resources in zygotes (including the unsandboxed zygote) allows them to be
@@ -1020,10 +1035,22 @@ int ContentMainRunnerImpl::Initialize(ContentMainParam
       process_type == switches::kZygoteProcess) {
     PreSandboxInit();
   }
+#elif BUILDFLAG(IS_BSD)
+  PreSandboxInit();
 #elif BUILDFLAG(IS_IOS) && !BUILDFLAG(IS_IOS_TVOS)
   ChildProcessEnterSandbox();
 #endif
 
+#if BUILDFLAG(IS_BSD)
+  if (process_type.empty()) {
+    sandbox::policy::SandboxLinux::Options sandbox_options;
+    sandbox::policy::SandboxLinux::GetInstance()->InitializeSandbox(
+        sandbox::policy::SandboxTypeFromCommandLine(
+            *base::CommandLine::ForCurrentProcess()),
+        sandbox::policy::SandboxLinux::PreSandboxHook(), sandbox_options);
+  }
+#endif
+
   delegate_->SandboxInitialized(process_type);
 
 #if BUILDFLAG(USE_ZYGOTE)
@@ -1125,6 +1152,11 @@ NO_STACK_PROTECTOR int ContentMainRunnerImpl::Run() {
   content_main_params_.reset();
 
   RegisterMainThreadFactories();
+
+#if BUILDFLAG(IS_BSD)
+  if (!process_type.empty())
+    PreSandboxInit();
+#endif 
 
   if (process_type.empty())
     return RunBrowser(std::move(main_params), start_minimal_browser);
