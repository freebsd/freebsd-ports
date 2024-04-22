--- chrome/common/url_constants.h.orig	2024-02-21 00:20:37 UTC
+++ chrome/common/url_constants.h
@@ -822,7 +822,7 @@ inline constexpr char kPhoneHubPermissionLearnMoreURL[
     "https://support.google.com/chromebook?p=multidevice";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome?p=chrome_app_deprecation";
