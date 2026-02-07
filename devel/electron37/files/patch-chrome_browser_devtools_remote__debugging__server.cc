--- chrome/browser/devtools/remote_debugging_server.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/devtools/remote_debugging_server.cc
@@ -109,7 +109,7 @@ IsRemoteDebuggingAllowed(const std::optional<bool>& is
         RemoteDebuggingServer::NotStartedReason::kDisabledByPolicy);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kDevToolsDebuggingRestrictions) &&
       is_default_user_data_dir.value_or(true)) {
     return base::unexpected(
