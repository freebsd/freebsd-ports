--- components/password_manager/core/browser/stub_password_manager_client.cc.orig	2024-06-18 21:43:29 UTC
+++ components/password_manager/core/browser/stub_password_manager_client.cc
@@ -175,7 +175,7 @@ version_info::Channel StubPasswordManagerClient::GetCh
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::unique_ptr<
     password_manager::PasswordCrossDomainConfirmationPopupController>
 StubPasswordManagerClient::ShowCrossDomainConfirmationPopup(
