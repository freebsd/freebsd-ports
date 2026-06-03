--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2026-01-07 00:52:53 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -701,7 +701,7 @@ bool ChromePasswordManagerClient::IsReauthBeforeFillin
 bool ChromePasswordManagerClient::IsReauthBeforeFillingRequired(
     device_reauth::DeviceAuthenticator* authenticator) {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!GetLocalStatePrefs() || !GetPrefs() || !authenticator) {
     return false;
   }
@@ -993,7 +993,7 @@ void ChromePasswordManagerClient::NotifyKeychainError(
 }
 
 void ChromePasswordManagerClient::NotifyKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PasswordsClientUIDelegate* manage_passwords_ui_controller =
       PasswordsClientUIDelegateFromWebContents(web_contents());
   if (manage_passwords_ui_controller) {
@@ -2028,7 +2028,7 @@ bool ChromePasswordManagerClient::IsPasswordManagement
 bool ChromePasswordManagerClient::IsPasswordManagementEnabledForCurrentPage(
     const GURL& url) const {
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (IsPasswordManagerForUrlDisallowedByPolicy(url)) {
     return false;
   }
@@ -2067,7 +2067,7 @@ bool ChromePasswordManagerClient::IsPasswordManagement
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool ChromePasswordManagerClient::IsPasswordManagerForUrlDisallowedByPolicy(
     const GURL& url) const {
   if (!GetPrefs() || !GetPrefs()->HasPrefPath(
