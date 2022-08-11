--- chrome/browser/intranet_redirect_detector.h.orig	2022-05-11 07:16:48 UTC
+++ chrome/browser/intranet_redirect_detector.h
@@ -27,7 +27,7 @@ class SimpleURLLoader;
 class PrefRegistrySimple;
 
 #if !(defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-      defined(OS_CHROMEOS) || defined(OS_FUCHSIA))
+      defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD))
 #error "IntranetRedirectDetector should only be built on Desktop platforms."
 #endif
 
