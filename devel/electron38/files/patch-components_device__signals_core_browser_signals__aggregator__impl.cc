--- components/device_signals/core/browser/signals_aggregator_impl.cc.orig	2025-03-24 20:50:14 UTC
+++ components/device_signals/core/browser/signals_aggregator_impl.cc
@@ -64,7 +64,7 @@ SignalsAggregatorImpl::~SignalsAggregatorImpl() = defa
 
 SignalsAggregatorImpl::~SignalsAggregatorImpl() = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SignalsAggregatorImpl::GetSignalsForUser(
     const UserContext& user_context,
     const SignalsAggregationRequest& request,
