--- chrome/browser/media/webrtc/capture_policy_utils.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/media/webrtc/capture_policy_utils.cc
@@ -139,7 +139,7 @@ void RegisterProfilePrefs(PrefRegistrySimple* registry
 }
 
 bool IsGetAllScreensMediaAllowedForAnySite(content::BrowserContext* context) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
@@ -174,7 +174,7 @@ bool IsGetAllScreensMediaAllowedForAnySite(content::Br
 
 bool IsGetAllScreensMediaAllowed(content::BrowserContext* context,
                                  const GURL& url) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   Profile* profile = Profile::FromBrowserContext(context);
   if (!profile) {
     return false;
