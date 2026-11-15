--- third_party/blink/common/features.cc.orig	2026-10-30 11:54:04 UTC
+++ third_party/blink/common/features.cc
@@ -1805,7 +1805,7 @@ BASE_FEATURE(kPreloadingEagerHoverHeuristics,
 // currently out of scope.
 BASE_FEATURE(kPreloadingEagerHoverHeuristics,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
