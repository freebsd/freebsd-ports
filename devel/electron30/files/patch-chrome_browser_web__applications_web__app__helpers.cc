--- chrome/browser/web_applications/web_app_helpers.cc.orig	2024-04-15 20:33:50 UTC
+++ chrome/browser/web_applications/web_app_helpers.cc
@@ -146,7 +146,7 @@ bool IsValidWebAppUrl(const GURL& app_url) {
 
   bool allow_extension_apps = true;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // Stop allowing apps to be extension urls when the shortcuts are separated -
   // they can be extension urls instead.
   allow_extension_apps =
