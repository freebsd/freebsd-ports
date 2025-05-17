--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -95,7 +95,7 @@ const char* const kBadFlags[] = {
     extensions::switches::kExtensionsOnChromeURLs,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
