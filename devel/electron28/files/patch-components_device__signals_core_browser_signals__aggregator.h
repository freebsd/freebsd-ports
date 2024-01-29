--- components/device_signals/core/browser/signals_aggregator.h.orig	2023-08-10 01:48:40 UTC
+++ components/device_signals/core/browser/signals_aggregator.h
@@ -22,7 +22,7 @@ class SignalsAggregator : public KeyedService {
 
   ~SignalsAggregator() override = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Will asynchronously collect signals whose names are specified in the
   // `request` object, and will also use a `user_context` to validate that the
   // user has permissions to the device's signals. Invokes `callback` with the
