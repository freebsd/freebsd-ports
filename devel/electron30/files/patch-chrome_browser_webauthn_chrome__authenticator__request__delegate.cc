--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2024-04-15 20:33:50 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -859,7 +859,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
