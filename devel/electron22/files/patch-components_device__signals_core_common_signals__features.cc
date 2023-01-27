--- components/device_signals/core/common/signals_features.cc.orig	2022-11-30 08:12:58 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -19,7 +19,7 @@ const base::FeatureParam<bool> kDisableAntiVirus{&kNew
 const base::FeatureParam<bool> kDisableHotfix{&kNewEvSignalsEnabled,
                                               "DisableHotfix", false};
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // Enables the consent promo for sharing device signal when a managed user
 // signs in on an unmanaged device. This occurs after the sign-in intercept
 // and before the sync promo (if enabled)
