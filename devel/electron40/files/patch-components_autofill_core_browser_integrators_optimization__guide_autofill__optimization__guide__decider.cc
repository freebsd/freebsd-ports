--- components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide_decider.cc.orig	2025-10-21 20:19:54 UTC
+++ components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide_decider.cc
@@ -203,7 +203,7 @@ void AddOptimizationTypesForBnplIssuers(
     base::flat_set<optimization_guide::proto::OptimizationType>&
         optimization_types) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto bnpl_issuer_allowlist_can_be_loaded =
       [&bnpl_issuers](BnplIssuer::IssuerId issuer_id) {
         return base::Contains(bnpl_issuers, issuer_id, &BnplIssuer::issuer_id);
