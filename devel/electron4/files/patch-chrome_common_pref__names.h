--- chrome/common/pref_names.h.orig	2019-03-15 06:37:09 UTC
+++ chrome/common/pref_names.h
@@ -166,7 +166,7 @@ extern const char kSearchSuggestEnabled[];
 extern const char kContextualSearchEnabled[];
 #endif  // defined(OS_ANDROID)
 #if defined(OS_MACOSX) || defined(OS_WIN) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+  (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kConfirmToQuitEnabled[];
 #endif
 #if defined(OS_MACOSX)
@@ -294,7 +294,7 @@ extern const char kForceYouTubeRestrict[];
 extern const char kForceSessionSync[];
 extern const char kAllowedDomainsForApps[];
 extern const char kSafeSitesFilterBehavior[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -327,7 +327,7 @@ extern const char kDefaultBrowserSettingEnabled[];
 #if defined(OS_MACOSX)
 extern const char kShowUpdatePromotionInfoBar[];
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -474,7 +474,7 @@ extern const char kAppWindowPlacement[];
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if defined(OS_ANDROID)
