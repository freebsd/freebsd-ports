--- components/password_manager/core/browser/sync/password_sync_bridge.cc.orig	2023-08-10 01:48:40 UTC
+++ components/password_manager/core/browser/sync/password_sync_bridge.cc
@@ -188,7 +188,7 @@ bool IsCredentialPhished(const sync_pb::PasswordSpecif
 // merge.
 bool ShouldRecoverPasswordsDuringMerge() {
   // Delete the local undecryptable copy when this is MacOS or Linux only.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
@@ -196,7 +196,7 @@ bool ShouldRecoverPasswordsDuringMerge() {
 }
 
 bool ShouldCleanSyncMetadataDuringStartupWhenDecryptionFails() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ShouldRecoverPasswordsDuringMerge() &&
          base::FeatureList::IsEnabled(
              features::kForceInitialSyncWhenDecryptionFails);
