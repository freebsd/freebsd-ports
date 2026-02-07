--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -246,7 +246,7 @@
 #include "components/spellcheck/browser/pref_names.h"
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #include "chrome/browser/enterprise/idle/action.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
@@ -583,7 +583,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kManagedDefaultSmartCardConnectSetting,
     base::Value::Type::INTEGER },
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kDeletingUndecryptablePasswordsEnabled,
     password_manager::prefs::kDeletingUndecryptablePasswordsEnabled,
     base::Value::Type::BOOLEAN },
@@ -957,7 +957,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::LIST },
 #endif // BUILDFLAG(ENABLE_EXTENSIONS_CORE)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) \
-     || BUILDFLAG(IS_MAC)
+     || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kRequireOnlineRevocationChecksForLocalAnchors,
     prefs::kCertRevocationCheckingRequiredLocalAnchors,
     base::Value::Type::BOOLEAN },
@@ -969,7 +969,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::LIST },
 #endif  // #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
         // || BUILDFLAG(IS_WIN)  || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   { key::kFullscreenAllowed,
     prefs::kFullscreenAllowed,
     base::Value::Type::BOOLEAN },
@@ -1839,7 +1839,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::INTEGER},
 #endif // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kGSSAPILibraryName,
     prefs::kGSSAPILibraryName,
     base::Value::Type::STRING },
@@ -1904,7 +1904,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kNetworkServiceSandboxEnabled,
     prefs::kNetworkServiceSandboxEnabled,
     base::Value::Type::BOOLEAN },
@@ -1924,12 +1924,12 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kTotalMemoryLimitMb,
     base::Value::Type::INTEGER },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kBackgroundModeEnabled,
     prefs::kBackgroundModeEnabled,
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kUnmanagedDeviceSignalsConsentFlowEnabled,
     device_signals::prefs::kUnmanagedDeviceSignalsConsentFlowEnabled,
     base::Value::Type::BOOLEAN },
@@ -1943,7 +1943,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kLiveTranslateEnabled,
     base::Value::Type::BOOLEAN },
 #endif // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kDefaultBrowserSettingEnabled,
     prefs::kDefaultBrowserSettingEnabled,
     base::Value::Type::BOOLEAN },
@@ -1955,7 +1955,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) \
-    || BUILDFLAG(IS_CHROMEOS)
+    || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAutoplayAllowed,
     prefs::kAutoplayAllowed,
     base::Value::Type::BOOLEAN },
@@ -2059,7 +2059,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kAlternativeBrowserPath,
     browser_switcher::prefs::kAlternativeBrowserPath,
     base::Value::Type::STRING },
@@ -2164,7 +2164,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
@@ -2238,7 +2238,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     ash::prefs::kUrlParameterToAutofillSAMLUsername,
     base::Value::Type::STRING },
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kNTPFooterExtensionAttributionEnabled,
     prefs::kNTPFooterExtensionAttributionEnabled,
     base::Value::Type::BOOLEAN },
@@ -2273,7 +2273,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kRestrictCoreSharingOnRenderer,
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kOutOfProcessSystemDnsResolutionEnabled,
     prefs::kOutOfProcessSystemDnsResolutionEnabled,
     base::Value::Type::BOOLEAN },
@@ -2304,7 +2304,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::INTEGER },
 #endif
 #if BUILDFLAG(ENABLE_EXTENSIONS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kExtensionInstallTypeBlocklist,
     extensions::pref_names::kExtensionInstallTypeBlocklist,
     base::Value::Type::LIST},
@@ -2327,7 +2327,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
   { key::kTabCompareSettings,
     optimization_guide::prefs::kProductSpecificationsEnterprisePolicyAllowed,
     base::Value::Type::INTEGER},
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   { key::kChromeForTestingAllowed,
     prefs::kChromeForTestingAllowed,
     base::Value::Type::BOOLEAN },
@@ -2403,7 +2403,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     policy_prefs::kBuiltInAIAPIsEnabled,
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FUCHSIA)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   { key::kNTPFooterManagementNoticeEnabled,
     prefs::kNTPFooterManagementNoticeEnabled,
     base::Value::Type::BOOLEAN },
@@ -2537,7 +2537,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
   // Policies for all platforms - End
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<IntRangePolicyHandler>(
       key::kMemorySaverModeSavings,
       performance_manager::user_tuning::prefs::kMemorySaverModeAggressiveness,
@@ -2816,7 +2816,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       key::kBrowsingDataLifetime, browsing_data::prefs::kBrowsingDataLifetime,
       chrome_schema));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<GuestModePolicyHandler>());
   handlers->AddHandler(std::make_unique<LocalSyncPolicyHandler>());
   handlers->AddHandler(std::make_unique<ThemeColorPolicyHandler>());
@@ -2910,7 +2910,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
   std::vector<std::unique_ptr<ConfigurationPolicyHandler>>
       signin_legacy_policies;
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   signin_legacy_policies.push_back(std::make_unique<SimplePolicyHandler>(
       key::kForceBrowserSignin, prefs::kForceBrowserSignin,
       base::Value::Type::BOOLEAN));
@@ -3288,7 +3288,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif
 
 #if BUILDFLAG(ENABLE_SPELLCHECK)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SpellcheckLanguagePolicyHandler>());
   handlers->AddHandler(
       std::make_unique<SpellcheckLanguageBlocklistPolicyHandler>(
@@ -3296,7 +3296,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SimplePolicyHandler>(
       key::kAllowSystemNotifications, prefs::kAllowSystemNotifications,
       base::Value::Type::BOOLEAN));
@@ -3349,7 +3349,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
   std::vector<GenAiDefaultSettingsPolicyHandler::GenAiPolicyDetails>
       gen_ai_default_policies;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   gen_ai_default_policies.emplace_back(
       key::kAutofillPredictionSettings,
       optimization_guide::prefs::
