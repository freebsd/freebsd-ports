--- components/feature_engagement/public/feature_constants.cc.orig	2022-09-24 10:57:32 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -24,7 +24,7 @@ const base::Feature kIPHDummyFeature{"IPH_Dummy",
                                      base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const base::Feature kIPHDesktopSharedHighlightingFeature{
     "IPH_DesktopSharedHighlighting", base::FEATURE_DISABLED_BY_DEFAULT};
 const base::Feature kIPHDesktopTabGroupsNewGroupFeature{
@@ -294,7 +294,7 @@ const base::Feature kIPHOverflowMenuTipFeature{
     "IPH_OverflowMenuTip", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 const base::Feature kIPHAutofillVirtualCardSuggestionFeature{
     "IPH_AutofillVirtualCardSuggestion", base::FEATURE_ENABLED_BY_DEFAULT};
