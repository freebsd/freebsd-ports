--- chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc
@@ -22,7 +22,7 @@
 #include "components/policy/core/common/management/management_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/desktop/desktop_attestation_service.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
