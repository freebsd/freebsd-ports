--- components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2025-08-26 20:49:50 UTC
+++ components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -779,7 +779,7 @@ payments::BnplManager* BrowserAutofillManager::GetPaym
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
