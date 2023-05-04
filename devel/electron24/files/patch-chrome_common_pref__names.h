--- chrome/common/pref_names.h.orig	2023-03-30 00:33:45 UTC
+++ chrome/common/pref_names.h
@@ -388,7 +388,7 @@ extern const char kUseAshProxy[];
 #endif  //  BUILDFLAG(IS_CHROMEOS_LACROS)
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // TODO(https://crbug.com/1317782): Remove in M110.
 extern const char kUsesSystemThemeDeprecated[];
 extern const char kSystemTheme[];
@@ -409,7 +409,7 @@ extern const char kShowUpdatePromotionInfoBar[];
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 extern const char kUseCustomChromeFrame[];
 #endif
 extern const char kPartitionDefaultZoomLevel[];
@@ -599,7 +599,7 @@ extern const char kDownloadAllowedURLsForOpenByPolicy[
 extern const char kDownloadDirUpgraded[];
 extern const char kDownloadLastCompleteTime[];
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -716,7 +716,7 @@ extern const char kWebAppsUninstalledDefaultChromeApps
 extern const char kWebAppsPreferences[];
 extern const char kWebAppsIsolationState[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 extern const char kWebAppsUrlHandlerInfo[];
 #endif
@@ -845,7 +845,7 @@ extern const char kGloballyScopeHTTPAuthCacheEnabled[]
 extern const char kAmbientAuthenticationInPrivateModesEnabled[];
 extern const char kBasicAuthOverHttpEnabled[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
 
@@ -1124,7 +1124,7 @@ extern const char kBlockAutoplayEnabled[];
 #endif
 extern const char kSandboxExternalProtocolBlocked[];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kAllowSystemNotifications[];
 #endif
 
@@ -1150,7 +1150,7 @@ extern const char kCACertificateManagementAllowed[];
 extern const char kChromeRootStoreEnabled[];
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // TODO(https://crbug.com/1406103): delete this after a few milestones.
 extern const char kEnforceLocalAnchorConstraintsEnabled[];
 #endif
@@ -1299,7 +1299,7 @@ extern const char kDIPSTimerLastUpdate[];
 extern const char kThrottleNonVisibleCrossOriginIframesAllowed[];
 extern const char kNewBaseUrlInheritanceBehaviorAllowed[];
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOutOfProcessSystemDnsResolutionEnabled[];
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
