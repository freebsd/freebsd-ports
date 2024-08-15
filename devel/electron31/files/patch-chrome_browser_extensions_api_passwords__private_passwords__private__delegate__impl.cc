--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -610,7 +610,7 @@ void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   PasswordsPrivateEventRouter* router =
       PasswordsPrivateEventRouterFactory::GetForProfile(profile_);
   if (router) {
