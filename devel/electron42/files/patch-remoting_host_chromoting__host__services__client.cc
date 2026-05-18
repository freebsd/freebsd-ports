--- remoting/host/chromoting_host_services_client.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/chromoting_host_services_client.cc
@@ -74,7 +74,7 @@ ChromotingHostServicesClient::ChromotingHostServicesCl
 
 ChromotingHostServicesClient::ChromotingHostServicesClient()
     : ChromotingHostServicesClient(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           std::vector{GetChromotingHostServicesServerName(),
                       GetLegacyChromotingHostServicesServerName()}
 #else
@@ -163,7 +163,7 @@ bool ChromotingHostServicesClient::EnsureSessionServic
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
