--- components/password_manager/core/browser/password_store_factory_util.cc.orig	2024-10-16 21:31:11 UTC
+++ components/password_manager/core/browser/password_store_factory_util.cc
@@ -29,7 +29,7 @@ LoginDatabase::DeletingUndecryptablePasswordsEnabled G
 LoginDatabase::DeletingUndecryptablePasswordsEnabled GetPolicyFromPrefs(
     PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return LoginDatabase::DeletingUndecryptablePasswordsEnabled(
       prefs->GetBoolean(prefs::kDeletingUndecryptablePasswordsEnabled));
 #else
