--- components/policy/core/common/policy_pref_names.h.orig	2025-06-30 07:04:30 UTC
+++ components/policy/core/common/policy_pref_names.h
@@ -91,7 +91,7 @@ extern const char kBuiltInAIAPIsEnabled[];
 #endif
 extern const char kBuiltInAIAPIsEnabled[];
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kPasswordManagerBlocklist[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
