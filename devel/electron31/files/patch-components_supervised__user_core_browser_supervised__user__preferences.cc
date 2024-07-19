--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2024-06-18 21:43:30 UTC
+++ components/supervised_user/core/browser/supervised_user_preferences.cc
@@ -153,7 +153,7 @@ void RegisterProfilePrefs(PrefRegistrySimple* registry
       static_cast<int>(FirstTimeInterstitialBannerState::kUnknown));
   registry->RegisterBooleanPref(prefs::kChildAccountStatusKnown, false);
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   registry->RegisterIntegerPref(
       prefs::kLocallyParentApprovedExtensionsMigrationState,
       static_cast<int>(
