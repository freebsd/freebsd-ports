--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h.orig	2024-06-18 21:43:24 UTC
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h
@@ -14,7 +14,7 @@
 #include "components/autofill/core/browser/payments/payments_window_manager.h"
 #include "content/public/browser/web_contents_observer.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_list_observer.h"
@@ -39,7 +39,7 @@ class DesktopPaymentsWindowManager : public PaymentsWi
 // WebContents of the original tab that the pop-up is created in. If there is a
 // pop-up currently present, `this` will observe the WebContents of that pop-up.
 class DesktopPaymentsWindowManager : public PaymentsWindowManager,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
                                      public BrowserListObserver,
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
                                      public content::WebContentsObserver {
@@ -58,7 +58,7 @@ class DesktopPaymentsWindowManager : public PaymentsWi
       content::NavigationHandle* navigation_handle) override;
   void WebContentsDestroyed() override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // BrowserListObserver:
   void OnBrowserSetLastActive(Browser* browser) override;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
@@ -132,7 +132,7 @@ class DesktopPaymentsWindowManager : public PaymentsWi
   std::unique_ptr<PaymentsWindowUserConsentDialogControllerImpl>
       payments_window_user_consent_dialog_controller_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<BrowserList, BrowserListObserver> scoped_observation_{
       this};
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
