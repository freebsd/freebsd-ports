--- chrome/browser/ui/browser_commands.h.orig	2022-05-25 04:00:50 UTC
+++ chrome/browser/ui/browser_commands.h
@@ -251,7 +251,7 @@ void ProcessInterceptedChromeURLNavigationInIncognito(
 void FollowSite(content::WebContents* web_contents);
 void UnfollowSite(content::WebContents* web_contents);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Triggers the Screen AI to be run once on the |browser|.
 void RunScreenAi(Browser* browser);
 #endif  // BUILDFLAG(IS_LINUX)
