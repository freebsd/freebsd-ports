--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2024-08-14 20:54:35 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -630,7 +630,7 @@ void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
