--- chrome/browser/upgrade_detector/version_history_client.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/upgrade_detector/version_history_client.cc
@@ -176,7 +176,7 @@ GURL GetVersionReleasesUrl(base::Version version) {
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
