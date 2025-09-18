--- components/password_manager/core/browser/password_store_factory_util.cc.orig	2025-08-26 20:49:50 UTC
+++ components/password_manager/core/browser/password_store_factory_util.cc
@@ -30,7 +30,7 @@ LoginDatabase::DeletingUndecryptablePasswordsEnabled G
 LoginDatabase::DeletingUndecryptablePasswordsEnabled GetPolicyFromPrefs(
     PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return LoginDatabase::DeletingUndecryptablePasswordsEnabled(
       prefs->GetBoolean(prefs::kDeletingUndecryptablePasswordsEnabled));
 #else
