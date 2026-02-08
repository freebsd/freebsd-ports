--- components/proxy_config/proxy_config_pref_names.h.orig	2026-01-07 00:52:53 UTC
+++ components/proxy_config/proxy_config_pref_names.h
@@ -28,7 +28,7 @@ inline constexpr char kProxyOverrideRulesScope[] = "pr
 inline constexpr char kProxyOverrideRulesScope[] = "proxy_override_rules_scope";
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Preference to store the value of the "EnableProxyOverrideRulesForAllUsers"
 // policy.
 inline constexpr char kEnableProxyOverrideRulesForAllUsers[] =
