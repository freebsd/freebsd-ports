--- components/device_signals/core/common/signals_features.h.orig	2022-11-30 08:12:58 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -20,7 +20,7 @@ extern const base::FeatureParam<bool> kDisableSettings
 extern const base::FeatureParam<bool> kDisableAntiVirus;
 extern const base::FeatureParam<bool> kDisableHotfix;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsPromoAfterSigninIntercept);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
