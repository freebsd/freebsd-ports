--- components/password_manager/core/browser/stub_password_manager_client.cc.orig	2025-06-30 07:04:30 UTC
+++ components/password_manager/core/browser/stub_password_manager_client.cc
@@ -206,7 +206,7 @@ version_info::Channel StubPasswordManagerClient::GetCh
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void StubPasswordManagerClient::OpenPasswordDetailsBubble(
     const password_manager::PasswordForm& form) {}
 void StubPasswordManagerClient::MaybeShowSavePasswordPrimingPromo(
