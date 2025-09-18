--- content/public/browser/content_browser_client.cc.orig	2025-09-10 14:33:47 UTC
+++ content/public/browser/content_browser_client.cc
@@ -1396,7 +1396,7 @@ bool ContentBrowserClient::ShouldRunOutOfProcessSystem
 // that can be adequately sandboxed.
 // Currently Android's network service will not run out of process or sandboxed,
 // so OutOfProcessSystemDnsResolution is not currently enabled on Android.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
