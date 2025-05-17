--- components/signin/public/base/signin_switches.h.orig	2025-04-22 20:15:27 UTC
+++ components/signin/public/base/signin_switches.h
@@ -52,7 +52,7 @@ BASE_DECLARE_FEATURE(kUseHostedDomainForManagementChec
 BASE_DECLARE_FEATURE(kUseHostedDomainForManagementCheckOnSignin);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kEnableHistorySyncOptin);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
