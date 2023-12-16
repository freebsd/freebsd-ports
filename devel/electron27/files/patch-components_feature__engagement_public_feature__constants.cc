--- components/feature_engagement/public/feature_constants.cc.orig	2023-10-19 19:58:18 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -21,7 +21,7 @@ BASE_FEATURE(kUseClientConfigIPH,
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillFeedbackNewBadgeFeature,
              "IPH_AutofillFeedbackNewBadge",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -519,7 +519,8 @@ BASE_FEATURE(kIPHiOSPromoPasswordManagerWidgetFeature,
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature,
              "IPH_AutofillExternalAccountProfileSuggestion",
              base::FEATURE_ENABLED_BY_DEFAULT);
