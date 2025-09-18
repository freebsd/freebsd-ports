--- components/policy/core/common/policy_pref_names.h.orig	2025-08-26 20:49:50 UTC
+++ components/policy/core/common/policy_pref_names.h
@@ -94,7 +94,7 @@ extern const char kBuiltInAIAPIsEnabled[];
 #endif
 extern const char kBuiltInAIAPIsEnabled[];
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kPasswordManagerBlocklist[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
