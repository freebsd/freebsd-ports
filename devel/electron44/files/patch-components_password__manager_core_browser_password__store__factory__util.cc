--- components/password_manager/core/browser/password_store_factory_util.cc.orig	2025-10-21 20:19:54 UTC
+++ components/password_manager/core/browser/password_store_factory_util.cc
@@ -33,7 +33,7 @@ LoginDatabase::DeletingUndecryptablePasswordsEnabled G
 LoginDatabase::DeletingUndecryptablePasswordsEnabled GetPolicyFromPrefs(
     PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   return LoginDatabase::DeletingUndecryptablePasswordsEnabled(
       prefs->GetBoolean(prefs::kDeletingUndecryptablePasswordsEnabled));
 #else
