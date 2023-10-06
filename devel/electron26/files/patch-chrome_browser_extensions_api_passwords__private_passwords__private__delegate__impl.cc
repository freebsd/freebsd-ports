--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2023-08-10 01:48:35 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -582,7 +582,7 @@ void PasswordsPrivateDelegateImpl::OsReauthCall(
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
