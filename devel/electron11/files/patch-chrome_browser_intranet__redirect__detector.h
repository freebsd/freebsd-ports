--- chrome/browser/intranet_redirect_detector.h.orig	2021-01-07 00:36:23 UTC
+++ chrome/browser/intranet_redirect_detector.h
@@ -27,7 +27,7 @@ class SimpleURLLoader;
 
 class PrefRegistrySimple;
 
-#if !(defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if !(defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) ||\
       defined(OS_CHROMEOS))
 #error "IntranetRedirectDetector should only be built on Desktop platforms."
 #endif
