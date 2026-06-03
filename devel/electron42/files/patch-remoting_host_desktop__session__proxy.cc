--- remoting/host/desktop_session_proxy.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/desktop_session_proxy.cc
@@ -163,7 +163,7 @@ DesktopSessionProxy::CreateRemoteWebAuthnStateChangeNo
       base::BindRepeating(&DesktopSessionProxy::SignalWebAuthnExtension, this));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopSessionProxy::OnSessionServicesClientConnected(
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
@@ -203,7 +203,7 @@ std::string DesktopSessionProxy::GetCapabilities() con
     result += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   result += " ";
   result += protocol::kClientControlledLayoutCapability;
 #endif
