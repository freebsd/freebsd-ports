--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -620,7 +620,7 @@ bool ChromePasswordManagerClient::IsReauthBeforeFillin
 bool ChromePasswordManagerClient::IsReauthBeforeFillingRequired(
     device_reauth::DeviceAuthenticator* authenticator) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -876,7 +876,7 @@ void ChromePasswordManagerClient::NotifyKeychainError(
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   if (manage_passwords_ui_controller) {
