--- remoting/host/chromoting_host_services_client.cc.orig	2023-08-10 01:48:48 UTC
+++ remoting/host/chromoting_host_services_client.cc
@@ -65,7 +65,7 @@ mojo::PendingRemote<mojom::ChromotingHostServices> Con
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 constexpr char
@@ -144,7 +144,7 @@ bool ChromotingHostServicesClient::EnsureSessionServic
   if (session_services_remote_.is_bound()) {
     return true;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!environment_->HasVar(kChromeRemoteDesktopSessionEnvVar)) {
     LOG(WARNING) << "Current desktop environment is not remotable.";
     return false;
