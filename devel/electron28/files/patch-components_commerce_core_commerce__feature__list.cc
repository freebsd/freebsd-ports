--- components/commerce/core/commerce_feature_list.cc.orig	2023-11-29 21:39:57 UTC
+++ components/commerce/core/commerce_feature_list.cc
@@ -225,7 +225,7 @@ BASE_FEATURE(kShoppingList, "ShoppingList", base::FEAT
 
 BASE_FEATURE(kShoppingList, "ShoppingList", base::FEATURE_DISABLED_BY_DEFAULT);
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kShoppingListRegionLaunched,
              "ShoppingListRegionLaunched",
              base::FEATURE_ENABLED_BY_DEFAULT);
