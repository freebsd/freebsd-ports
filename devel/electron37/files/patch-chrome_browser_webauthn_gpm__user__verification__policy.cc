--- chrome/browser/webauthn/gpm_user_verification_policy.cc.orig	2024-08-14 20:54:41 UTC
+++ chrome/browser/webauthn/gpm_user_verification_policy.cc
@@ -17,7 +17,7 @@ bool GpmWillDoUserVerification(device::UserVerificatio
       return platform_has_biometrics;
 #elif BUILDFLAG(IS_MAC)
       return platform_has_biometrics;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return false;
 #else
       // This default is for unit tests.
