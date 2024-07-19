--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2024-06-18 21:43:29 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -196,7 +196,7 @@ bool ShouldCleanSyncMetadataDuringStartupWhenDecryptio
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
