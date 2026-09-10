--- chrome/test/supervised_user/google_auth_state_waiter_mixin.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/test/supervised_user/google_auth_state_waiter_mixin.cc
@@ -24,7 +24,7 @@ void GoogleAuthStateWaiterMixin::SetUpOnMainThread() {
 GoogleAuthStateWaiterMixin::~GoogleAuthStateWaiterMixin() = default;
 
 void GoogleAuthStateWaiterMixin::SetUpOnMainThread() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ChildAccountService* child_account_service =
       ChildAccountServiceFactory::GetForProfile(
           test_base_->browser()->GetProfile());
