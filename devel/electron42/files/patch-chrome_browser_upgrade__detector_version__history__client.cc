--- chrome/browser/upgrade_detector/version_history_client.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/upgrade_detector/version_history_client.cc
@@ -177,7 +177,7 @@ GURL GetVersionReleasesUrl(base::Version version) {
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
