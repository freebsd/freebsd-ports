--- components/enterprise/data_controls/core/browser/features.h.orig	2025-08-26 20:49:50 UTC
+++ components/enterprise/data_controls/core/browser/features.h
@@ -16,7 +16,7 @@ BASE_DECLARE_FEATURE(kEnableClipboardDataControlsAndro
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Controls enabling Data Controls rules for downloads on desktop
 BASE_DECLARE_FEATURE(kEnableDownloadDataControlsDesktop);
 #endif
