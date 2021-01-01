--- chrome/browser/flag_descriptions.h.orig	2019-03-15 06:37:03 UTC
+++ chrome/browser/flag_descriptions.h
@@ -2087,7 +2087,7 @@ extern const char kEnableContinueReadingDescription[];
 
 // Random platform combinations -----------------------------------------------
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kEnableInputImeApiName[];
 extern const char kEnableInputImeApiDescription[];
@@ -2099,7 +2099,7 @@ extern const char kWarnBeforeQuittingFlagDescription[]
 
 #endif  // !defined(OS_CHROMEOS)
 
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kExperimentalUiName[];
 extern const char kExperimentalUiDescription[];
@@ -2111,12 +2111,12 @@ extern const char kAutomaticTabDiscardingDescription[]
 
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 extern const char kDirectManipulationStylusName[];
 extern const char kDirectManipulationStylusDescription[];
 
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Feature flags --------------------------------------------------------------
 
