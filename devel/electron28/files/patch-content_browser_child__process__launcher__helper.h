--- content/browser/child_process_launcher_helper.h.orig	2023-11-29 21:40:01 UTC
+++ content/browser/child_process_launcher_helper.h
@@ -262,7 +262,7 @@ class ChildProcessLauncherHelper
   std::unique_ptr<SandboxedProcessLauncherDelegate> delegate_;
   base::WeakPtr<ChildProcessLauncher> child_process_launcher_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The priority of the process. The state is stored to avoid changing the
   // setting repeatedly.
   absl::optional<base::Process::Priority> priority_;
