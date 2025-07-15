--- components/autofill/core/browser/foundations/browser_autofill_manager.cc.orig	2025-06-30 07:04:30 UTC
+++ components/autofill/core/browser/foundations/browser_autofill_manager.cc
@@ -740,7 +740,7 @@ payments::BnplManager* BrowserAutofillManager::GetPaym
 
 payments::BnplManager* BrowserAutofillManager::GetPaymentsBnplManager() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!bnpl_manager_) {
     bnpl_manager_ = std::make_unique<payments::BnplManager>(this);
   }
