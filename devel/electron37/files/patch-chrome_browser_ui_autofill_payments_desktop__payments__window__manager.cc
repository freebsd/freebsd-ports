--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc
@@ -58,7 +58,7 @@ DesktopPaymentsWindowManager::DesktopPaymentsWindowMan
 DesktopPaymentsWindowManager::DesktopPaymentsWindowManager(
     ContentAutofillClient* client)
     : client_(CHECK_DEREF(client)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scoped_observation_.Observe(BrowserList::GetInstance());
 #endif  // BUILDFLAG(IS_LINUX)
 }
@@ -144,7 +144,7 @@ void DesktopPaymentsWindowManager::WebContentsDestroye
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopPaymentsWindowManager::OnBrowserSetLastActive(Browser* browser) {
   // If there is an ongoing payments window manager pop-up flow, and the
   // original tab's WebContents become active, activate the pop-up's
