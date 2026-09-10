--- components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc.orig	2026-08-24 20:59:34 UTC
+++ components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc
@@ -1289,7 +1289,7 @@ bool IsBnplIssuerSupported() {
 
 bool IsBnplIssuerSupported() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kAutofillEnableBuyNowPayLaterSyncing);
 #else
