--- components/policy/core/browser/url_blocklist_manager.cc.orig	2025-06-30 07:04:30 UTC
+++ components/policy/core/browser/url_blocklist_manager.cc
@@ -377,7 +377,7 @@ void URLBlocklistManager::RegisterProfilePrefs(
       policy_prefs::kSafeSitesFilterBehavior,
       static_cast<int>(SafeSitesFilterBehavior::kSafeSitesFilterDisabled));
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(policy_prefs::kPasswordManagerBlocklist);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_MAC)
