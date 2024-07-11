--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2024-04-15 20:33:55 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -195,7 +195,7 @@ bool ShouldCleanSyncMetadataDuringStartupWhenDecryptio
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
