--- components/autofill/core/browser/data_manager/payments/payments_data_manager.h.orig	2025-06-30 07:04:30 UTC
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.h
@@ -365,7 +365,7 @@ class PaymentsDataManager : public AutofillWebDataServ
   void SetAutofillHasSeenIban();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns the value of the kAutofillHasSeenBnpl pref.
   bool IsAutofillHasSeenBnplPrefEnabled() const;
 
@@ -685,7 +685,7 @@ class PaymentsDataManager : public AutofillWebDataServ
   void ClearAllCreditCardBenefits();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Monitors the `kAutofillBnplEnabled` preference for changes and controls the
   // clearing/loading of payment instruments accordingly. Will also log the
   // `Autofill.SettingsPage.BnplToggled` metric.
