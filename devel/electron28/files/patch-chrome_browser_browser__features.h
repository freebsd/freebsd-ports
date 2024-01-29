--- chrome/browser/browser_features.h.orig	2023-11-29 21:39:47 UTC
+++ chrome/browser/browser_features.h
@@ -121,7 +121,7 @@ BASE_DECLARE_FEATURE(kOmniboxTriggerForNoStatePrefetch
 
 BASE_DECLARE_FEATURE(kOmniboxTriggerForNoStatePrefetch);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kPayloadTestComponent);
 #endif
 
