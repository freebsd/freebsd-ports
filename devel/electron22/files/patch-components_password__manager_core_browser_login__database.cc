--- components/password_manager/core/browser/login_database.cc.orig	2022-11-30 08:12:58 UTC
+++ components/password_manager/core/browser/login_database.cc
@@ -732,7 +732,7 @@ std::string GeneratePlaceholders(size_t count) {
   return result;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Fills |form| with necessary data required to be removed from the database
 // and returns it.
 PasswordForm GetFormForRemoval(sql::Statement& statement) {
@@ -749,7 +749,7 @@ PasswordForm GetFormForRemoval(sql::Statement& stateme
 // Whether we should try to return the decryptable passwords while the
 // encryption service fails for some passwords.
 bool ShouldReturnPartialPasswords() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kSkipUndecryptablePasswords);
 #else
   return false;
@@ -1578,7 +1578,7 @@ bool LoginDatabase::DeleteAndRecreateDatabaseFile() {
 }
 
 DatabaseCleanupResult LoginDatabase::DeleteUndecryptableLogins() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   TRACE_EVENT0("passwords", "LoginDatabase::DeleteUndecryptableLogins");
   // If the Keychain in MacOS or the real secret key in Linux is unavailable,
   // don't delete any logins.
