--- components/commerce/core/commerce_feature_list.cc.orig	2026-03-13 16:54:03 UTC
+++ components/commerce/core/commerce_feature_list.cc
@@ -176,7 +176,7 @@ const char kDiscountOnShoppyPageParam[] = "discount-on
 const char kDiscountOnShoppyPageParam[] = "discount-on-shoppy-page";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD) 
 const base::FeatureParam<bool> kDiscountOnShoppyPage{
     &kEnableDiscountInfoApi, kDiscountOnShoppyPageParam, true};
 #else
@@ -189,7 +189,7 @@ const char kNonMerchantWideBehaviorParam[] = "non-merc
 const char kNonMerchantWideBehaviorParam[] = "non-merchant-wide-behavior";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kDiscountDialogAutoPopupBehaviorSetting,
              base::FEATURE_ENABLED_BY_DEFAULT);
 const base::FeatureParam<int> kHistoryClustersBehavior{
