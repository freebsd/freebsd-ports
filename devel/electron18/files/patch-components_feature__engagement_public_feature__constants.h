--- components/feature_engagement/public/feature_constants.h.orig	2022-05-19 05:17:40 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -30,7 +30,7 @@ extern const base::Feature kUseClientConfigIPH;
 extern const base::Feature kIPHDummyFeature;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 extern const base::Feature kIPHDesktopSharedHighlightingFeature;
 extern const base::Feature kIPHDesktopTabGroupsNewGroupFeature;
 extern const base::Feature kIPHFocusHelpBubbleScreenReaderPromoFeature;
@@ -174,7 +174,7 @@ extern const base::Feature kIPHDiscoverFeedHeaderFeatu
 extern const base::Feature kIPHDefaultSiteViewFeature;
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 extern const base::Feature kIPHAutofillVirtualCardSuggestionFeature;
 extern const base::Feature kIPHUpdatedConnectionSecurityIndicatorsFeature;
