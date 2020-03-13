--- chrome/browser/password_manager/password_store_factory.cc.orig	2019-12-12 12:39:11 UTC
+++ chrome/browser/password_manager/password_store_factory.cc
@@ -181,7 +181,7 @@ PasswordStoreFactory::BuildServiceInstanceFor(
                         base::TimeDelta::FromSeconds(20));
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
           IdentityManagerFactory::GetForProfile(profile));
