--- chrome/browser/enterprise/signals/signals_aggregator_factory.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/enterprise/signals/signals_aggregator_factory.cc
@@ -49,7 +49,7 @@
 #include "components/device_signals/core/browser/settings_client.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/agent_signals_collector.h"
 #include "components/device_signals/core/browser/crowdstrike_client.h"
 #include "components/device_signals/core/browser/detected_agent_client.h"
@@ -114,7 +114,7 @@ SignalsAggregatorFactory::BuildServiceInstanceForBrows
           service_host));
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   collectors.push_back(std::make_unique<device_signals::AgentSignalsCollector>(
       device_signals::CrowdStrikeClient::Create(),
       device_signals::DetectedAgentClient::Create()));
