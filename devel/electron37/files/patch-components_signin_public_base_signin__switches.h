--- components/signin/public/base/signin_switches.h.orig	2025-06-30 07:04:30 UTC
+++ components/signin/public/base/signin_switches.h
@@ -58,7 +58,7 @@ BASE_DECLARE_FEATURE(kFullscreenSignInPromoUseDate);
 BASE_DECLARE_FEATURE(kFullscreenSignInPromoUseDate);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kEnableHistorySyncOptin);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
