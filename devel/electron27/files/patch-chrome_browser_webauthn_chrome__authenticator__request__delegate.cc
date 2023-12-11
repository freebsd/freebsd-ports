--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2023-10-19 19:58:08 UTC
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -670,7 +670,7 @@ void ChromeAuthenticatorRequestDelegate::ConfigureDisc
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
@@ -886,7 +886,11 @@ void ChromeAuthenticatorRequestDelegate::OnTransportAv
     if (data.has_platform_authenticator_credential ==
             device::FidoRequestHandlerBase::RecognizedCredential::
                 kHasRecognizedCredential &&
+#if (_LIBCPP_VERSION >= 160000)
         std::ranges::none_of(data.recognized_credentials,
+#else
+        base::ranges::none_of(data.recognized_credentials,
+#endif
                              IsCredentialFromPlatformAuthenticator)) {
       data.has_platform_authenticator_credential = device::
           FidoRequestHandlerBase::RecognizedCredential::kNoRecognizedCredential;
