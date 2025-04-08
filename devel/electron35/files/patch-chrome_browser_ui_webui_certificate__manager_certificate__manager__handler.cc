--- chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc
@@ -221,7 +221,7 @@ CertificateManagerPageHandler::GetCertSource(
                 CERTIFICATE_TRUST_TYPE_DISTRUSTED,
             profile_, &remote_client_);
         break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       case certificate_manager_v2::mojom::CertificateSource::
           kProvisionedClientCert:
         source_ptr = CreateProvisionedClientCertSource(profile_);
