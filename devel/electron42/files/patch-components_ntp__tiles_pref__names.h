--- components/ntp_tiles/pref_names.h.orig	2026-01-07 00:52:53 UTC
+++ components/ntp_tiles/pref_names.h
@@ -49,7 +49,7 @@ inline constexpr char kCustomLinksInitialized[] = "cus
 
 // Prefs used to cache enterprise shortcuts.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kEnterpriseShortcutsPolicyList[] =
     "enterprise_shortcuts.policy_list";
 inline constexpr char kEnterpriseShortcutsUserList[] =
