--- components/password_manager/core/browser/stub_password_manager_client.h.orig	2025-06-30 07:04:30 UTC
+++ components/password_manager/core/browser/stub_password_manager_client.h
@@ -77,7 +77,7 @@ class StubPasswordManagerClient : public PasswordManag
   MockPasswordFeatureManager* GetPasswordFeatureManager();
   version_info::Channel GetChannel() const override;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OpenPasswordDetailsBubble(
       const password_manager::PasswordForm& form) override;
   void MaybeShowSavePasswordPrimingPromo(const GURL& current_url) override;
