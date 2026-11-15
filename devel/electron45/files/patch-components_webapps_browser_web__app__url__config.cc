--- components/webapps/browser/web_app_url_config.cc.orig	2026-04-28 21:06:17 UTC
+++ components/webapps/browser/web_app_url_config.cc
@@ -35,7 +35,7 @@ bool IsUrlEligibleForWebApp(const GURL& url) {
   }
 
   bool allow_extension_apps = true;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Stop allowing apps to be extension URLs when the shortcuts are separated -
   // they can be extension URLs instead.
   allow_extension_apps = false;
