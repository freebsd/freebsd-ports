--- chrome/common/chrome_features.h.orig	2019-03-15 06:37:09 UTC
+++ chrome/common/chrome_features.h
@@ -52,7 +52,7 @@ extern const base::Feature kAsyncDns;
 extern const base::Feature kAutomaticTabDiscarding;
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // defined(OS_WIN) || defined(OS_LINUX)
 
@@ -76,7 +76,7 @@ extern const base::Feature kDialogTouchBar;
 extern const base::Feature kTabStripKeyboardFocus;
 #endif  // defined(OS_MACOSX)
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const base::Feature kCertDualVerificationTrialFeature;
 #endif
 
