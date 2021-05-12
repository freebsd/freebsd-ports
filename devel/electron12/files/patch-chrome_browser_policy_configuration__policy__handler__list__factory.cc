--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1233,11 +1233,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !defined(OS_MAC) && !BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
-#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if !defined(OS_MAC)
   { key::kFullscreenAllowed,
@@ -1282,11 +1282,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   { key::kAllowNativeNotifications,
     prefs::kAllowNativeNotifications,
     base::Value::Type::BOOLEAN },
-#endif // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || deined(OS_BSD)
 
   { key::kScrollToTextFragmentEnabled,
     prefs::kScrollToTextFragmentEnabled,
