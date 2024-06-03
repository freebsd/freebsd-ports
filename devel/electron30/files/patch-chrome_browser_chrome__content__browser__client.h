--- chrome/browser/chrome_content_browser_client.h.orig	2024-04-15 20:33:46 UTC
+++ chrome/browser/chrome_content_browser_client.h
@@ -500,7 +500,7 @@ class ChromeContentBrowserClient : public content::Con
   bool IsPluginAllowedToUseDevChannelAPIs(
       content::BrowserContext* browser_context,
       const GURL& url) override;
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   void GetAdditionalMappedFilesForChildProcess(
       const base::CommandLine& command_line,
       int child_process_id,
