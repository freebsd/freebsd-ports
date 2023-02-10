--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -93,7 +93,7 @@ static const char* kBadFlags[] = {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
