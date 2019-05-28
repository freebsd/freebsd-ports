--- chrome/browser/password_manager/password_store_factory.cc.orig	2019-03-15 06:37:03 UTC
+++ chrome/browser/password_manager/password_store_factory.cc
@@ -283,7 +283,7 @@ PasswordStoreFactory::BuildServiceInstanceFor(
   password_manager_util::CleanUserDataInBlacklistedCredentials(
       ps.get(), profile->GetPrefs(), 60);
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
