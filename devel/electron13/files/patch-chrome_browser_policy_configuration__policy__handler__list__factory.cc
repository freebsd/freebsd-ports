--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1293,11 +1293,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !defined(OS_MAC) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
-#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if !defined(OS_MAC)
   { key::kFullscreenAllowed,
@@ -1650,14 +1650,14 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD)
   handlers->AddHandler(
       std::make_unique<
           enterprise_connectors::EnterpriseConnectorsPolicyHandler>(
           key::kContextAwareAccessSignalsAllowlist,
           enterprise_connectors::kContextAwareAccessSignalsAllowlistPref,
           chrome_schema));
-#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   handlers->AddHandler(std::make_unique<extensions::ExtensionListPolicyHandler>(
@@ -2012,13 +2012,13 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       SimpleSchemaValidatingPolicyHandler::RECOMMENDED_PROHIBITED,
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   handlers->AddHandler(std::make_unique<SimpleSchemaValidatingPolicyHandler>(
       key::kWebAppSettings, prefs::kWebAppSettings, chrome_schema,
       SCHEMA_ALLOW_UNKNOWN,
       SimpleSchemaValidatingPolicyHandler::RECOMMENDED_PROHIBITED,
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
@@ -2031,7 +2031,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   handlers->AddHandler(std::make_unique<SimpleDeprecatingPolicyHandler>(
       std::make_unique<SimplePolicyHandler>(key::kAllowNativeNotifications,
                                             prefs::kAllowNativeNotifications,
@@ -2039,7 +2039,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       std::make_unique<SimplePolicyHandler>(key::kAllowSystemNotifications,
                                             prefs::kAllowSystemNotifications,
                                             base::Value::Type::BOOLEAN)));
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
   return handlers;
 }
