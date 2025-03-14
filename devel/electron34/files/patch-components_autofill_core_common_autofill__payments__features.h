--- components/autofill/core/common/autofill_payments_features.h.orig	2025-01-27 17:37:37 UTC
+++ components/autofill/core/common/autofill_payments_features.h
@@ -17,7 +17,7 @@ BASE_DECLARE_FEATURE(kAutofillDisableLocalCardMigratio
 BASE_DECLARE_FEATURE(kAutofillDisableLocalCardMigration);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(AUTOFILL)
 BASE_DECLARE_FEATURE(kAutofillEnableAmountExtractionDesktop);
 #endif
