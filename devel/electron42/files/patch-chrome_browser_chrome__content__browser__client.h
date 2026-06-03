--- chrome/browser/chrome_content_browser_client.h.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -574,7 +574,7 @@ class ChromeContentBrowserClient : public content::Con
       const GURL& site_url) override;
   std::unique_ptr<content::TracingDelegate> CreateTracingDelegate() override;
   bool IsSystemWideTracingEnabled() override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
