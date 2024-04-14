--- chrome/browser/intranet_redirect_detector.h.orig	2023-11-29 21:39:48 UTC
+++ chrome/browser/intranet_redirect_detector.h
@@ -25,7 +25,7 @@ class PrefRegistrySimple;
 class PrefRegistrySimple;
 
 #if !(BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-      BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA))
+      BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
 #error "IntranetRedirectDetector should only be built on Desktop platforms."
 #endif
 
