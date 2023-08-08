--- chrome/common/url_constants.h.orig	2022-11-30 08:12:58 UTC
+++ chrome/common/url_constants.h
@@ -471,7 +471,7 @@ extern const char kOutdatedPluginLearnMoreURL[];
 extern const char kPhoneHubPermissionLearnMoreURL[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 // "Learn more" URL for the chrome apps deprecation dialog.
 extern const char kChromeAppsDeprecationLearnMoreURL[];
