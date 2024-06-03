--- components/device_signals/core/browser/signals_aggregator_impl.h.orig	2023-08-10 01:48:40 UTC
+++ components/device_signals/core/browser/signals_aggregator_impl.h
@@ -29,7 +29,7 @@ class SignalsAggregatorImpl : public SignalsAggregator
   ~SignalsAggregatorImpl() override;
 
   // SignalsAggregator:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void GetSignalsForUser(const UserContext& user_context,
                          const SignalsAggregationRequest& request,
                          GetSignalsCallback callback) override;
