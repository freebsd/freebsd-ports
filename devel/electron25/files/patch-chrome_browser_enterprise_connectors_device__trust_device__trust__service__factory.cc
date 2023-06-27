--- chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc.orig	2023-03-30 00:33:42 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service_factory.cc
@@ -21,7 +21,7 @@
 #include "components/policy/core/common/management/management_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/attestation/desktop/desktop_attestation_service.h"
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
@@ -75,7 +75,7 @@ DeviceTrustServiceFactory::DeviceTrustServiceFactory()
   DependsOn(DeviceTrustConnectorServiceFactory::GetInstance());
   DependsOn(policy::ManagementServiceFactory::GetInstance());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Depends on this service via the SignalsService having a dependency on it.
   DependsOn(enterprise_signals::SignalsAggregatorFactory::GetInstance());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
