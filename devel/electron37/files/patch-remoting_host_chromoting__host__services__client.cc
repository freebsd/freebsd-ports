--- remoting/host/chromoting_host_services_client.cc.orig	2025-06-30 07:04:30 UTC
+++ remoting/host/chromoting_host_services_client.cc
@@ -134,7 +134,7 @@ bool ChromotingHostServicesClient::EnsureSessionServic
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
