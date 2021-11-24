--- chrome/browser/chrome_content_browser_client.h.orig	2021-07-15 19:13:32 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -395,12 +395,12 @@ class ChromeContentBrowserClient : public content::Con
   void OverridePageVisibilityState(
       content::RenderFrameHost* render_frame_host,
       content::PageVisibilityState* visibility_state) override;
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
       content::PosixFileDescriptorInfo* mappings) override;
-#endif  // defined(OS_POSIX) && !defined(OS_MAC)
+#endif  // defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 #if defined(OS_WIN)
   bool PreSpawnChild(sandbox::TargetPolicy* policy,
                      sandbox::policy::SandboxType sandbox_type,
