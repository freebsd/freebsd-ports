--- components/device_signals/core/common/signals_features.h.orig	2022-09-24 10:57:32 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -20,7 +20,7 @@ extern const base::FeatureParam<bool> kDisableSettings
 extern const base::FeatureParam<bool> kDisableAntiVirus;
 extern const base::FeatureParam<bool> kDisableHotfix;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const base::Feature kDeviceSignalsPromoAfterSigninIntercept;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
