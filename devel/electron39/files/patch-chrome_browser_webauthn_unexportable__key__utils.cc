--- chrome/browser/webauthn/unexportable_key_utils.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/webauthn/unexportable_key_utils.cc
@@ -33,7 +33,7 @@ GetWebAuthnUnexportableKeyProvider() {
   // If there is a scoped UnexportableKeyProvider configured, we always use
   // that so that tests can still override the key provider.
   const bool use_software_provider =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       !crypto::internal::HasScopedUnexportableKeyProvider();
 #else
       false;
