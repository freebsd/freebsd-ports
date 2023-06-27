--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2023-05-25 00:41:51 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -186,7 +186,7 @@ bool IsCredentialPhished(const sync_pb::PasswordSpecif
 // merge.
 bool ShouldRecoverPasswordsDuringMerge() {
   // Delete the local undecryptable copy when this is MacOS or Linux only.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
@@ -194,7 +194,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
