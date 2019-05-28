--- chrome/browser/flag_descriptions.cc.orig	2019-03-15 06:37:03 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -3411,7 +3411,7 @@ extern const char kEnableContinueReadingDescription[] 
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kEnableInputImeApiName[] = "Enable Input IME API";
 const char kEnableInputImeApiDescription[] =
@@ -3425,7 +3425,7 @@ const char kWarnBeforeQuittingFlagDescription[] =
 
 #endif  // !defined(OS_CHROMEOS)
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN) || defined(OS_MACOSX)
 
@@ -3438,13 +3438,13 @@ const char kAutomaticTabDiscardingDescription[] =
 
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kDirectManipulationStylusName[] = "Direct Manipulation Stylus";
 const char kDirectManipulationStylusDescription[] =
     "If enabled, Chrome will scroll web pages on stylus drag.";
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 const char kExperimentalUiName[] = "Use all upcoming UI features";
 const char kExperimentalUiDescription[] = "Use all upcoming UI features.";
