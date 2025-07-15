--- components/commerce/core/commerce_feature_list.cc.orig	2025-06-30 07:04:30 UTC
+++ components/commerce/core/commerce_feature_list.cc
@@ -157,7 +157,8 @@ BASE_FEATURE(kPriceInsights,
              "PriceInsights",
              base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_ANDROID) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kPriceInsightsRegionLaunched,
              "PriceInsightsRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -230,7 +231,7 @@ const char kDiscountOnShoppyPageParam[] = "discount-on
 const char kDiscountOnShoppyPageParam[] = "discount-on-shoppy-page";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const base::FeatureParam<bool> kDiscountOnShoppyPage{
     &kEnableDiscountInfoApi, kDiscountOnShoppyPageParam, true};
 #else
@@ -239,7 +240,7 @@ const base::FeatureParam<bool> kDiscountOnShoppyPage{
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDiscountInfoApiRegionLaunched,
              "EnableDiscountInfoApiRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -254,7 +255,7 @@ const char kNonMerchantWideBehaviorParam[] = "non-merc
 const char kNonMerchantWideBehaviorParam[] = "non-merchant-wide-behavior";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDiscountDialogAutoPopupBehaviorSetting,
              "DiscountDialogAutoPopupBehaviorSetting",
              base::FEATURE_ENABLED_BY_DEFAULT);
