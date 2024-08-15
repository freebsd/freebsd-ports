--- remoting/host/chromoting_host_services_client.cc.orig	2023-10-19 19:58:29 UTC
+++ remoting/host/chromoting_host_services_client.cc
@@ -59,7 +59,7 @@ mojo::PendingRemote<mojom::ChromotingHostServices> Con
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 constexpr char
@@ -136,7 +136,7 @@ bool ChromotingHostServicesClient::EnsureSessionServic
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
