--- chrome/common/chrome_features.h.orig	2019-09-10 11:13:45 UTC
+++ chrome/common/chrome_features.h
@@ -65,10 +65,10 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kAutoFetchOnNetErrorPage;
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBlockPromptsIfDismissedOften;
@@ -84,7 +84,7 @@ extern const base::Feature kBrowserHangFixesExperiment
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBundledConnectionHelpFeature;
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kCertDualVerificationTrialFeature;
 #endif
