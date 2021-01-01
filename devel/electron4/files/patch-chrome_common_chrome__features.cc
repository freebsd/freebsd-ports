--- chrome/common/chrome_features.cc.orig	2019-03-15 06:37:09 UTC
+++ chrome/common/chrome_features.cc
@@ -90,13 +90,13 @@ const base::Feature kAutomaticTabDiscarding{"Automatic
                                             base::FEATURE_ENABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN) || defined(OS_MACOSX)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
 const base::Feature kBackgroundModeAllowRestart{
     "BackgroundModeAllowRestart", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Enables or disables whether permission prompts are automatically blocked
 // after the user has explicitly dismissed them too many times.
@@ -155,7 +155,7 @@ const base::Feature kThirdPartyModulesBlocking{
     "ThirdPartyModulesBlocking", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 // Enables the dual certificate verification trial feature.
 // https://crbug.com/649026
 const base::Feature kCertDualVerificationTrialFeature{
@@ -365,7 +365,7 @@ const base::Feature kAcknowledgeNtpOverrideOnDeactivat
     "AcknowledgeNtpOverrideOnDeactivate", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 const base::Feature kWarnBeforeQuitting{"WarnBeforeQuitting",
                                         base::FEATURE_DISABLED_BY_DEFAULT};
 #endif
@@ -388,7 +388,7 @@ const base::Feature kModalPermissionPrompts{"ModalPerm
 // Center for displaying the toasts. The feature is hardcoded to enabled for
 // Chrome OS.
 #if BUILDFLAG(ENABLE_NATIVE_NOTIFICATIONS) && !defined(OS_CHROMEOS)
-#if defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 const base::Feature kNativeNotifications{"NativeNotifications",
                                          base::FEATURE_ENABLED_BY_DEFAULT};
 #else
