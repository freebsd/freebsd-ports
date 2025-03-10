--- chrome/browser/chrome_browser_field_trials.cc.orig	2024-08-14 20:54:34 UTC
+++ chrome/browser/chrome_browser_field_trials.cc
@@ -48,7 +48,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_trial.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/base/ui_base_features.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -155,7 +155,7 @@ void ChromeBrowserFieldTrials::RegisterSyntheticTrials
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // On Linux/Desktop platform variants, such as ozone/wayland, some features
 // might need to be disabled as per OzonePlatform's runtime properties.
 // OzonePlatform selection and initialization, in turn, depend on Chrome flags
