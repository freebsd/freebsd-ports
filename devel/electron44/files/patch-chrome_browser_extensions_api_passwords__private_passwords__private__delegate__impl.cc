--- chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/extensions/api/passwords_private/passwords_private_delegate_impl.cc
@@ -641,7 +641,7 @@ void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall
 }
 
 void PasswordsPrivateDelegateImpl::OsReauthTimeoutCall() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event_router_) {
     event_router_->OnPasswordManagerAuthTimeout();
   }
