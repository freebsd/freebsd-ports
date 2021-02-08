--- chrome/browser/password_manager/password_store_factory.cc.orig	2021-01-07 00:36:23 UTC
+++ chrome/browser/password_manager/password_store_factory.cc
@@ -188,7 +188,7 @@ PasswordStoreFactory::BuildServiceInstanceFor(
                                                   network_context_getter);
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
           IdentityManagerFactory::GetForProfile(profile));
