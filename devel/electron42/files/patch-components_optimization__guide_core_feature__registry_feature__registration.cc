--- components/optimization_guide/core/feature_registry/feature_registration.cc.orig	2026-04-28 21:06:17 UTC
+++ components/optimization_guide/core/feature_registry/feature_registration.cc
@@ -83,7 +83,7 @@ BASE_FEATURE(kFormsClassificationsMqlsLogging,
 
 BASE_FEATURE(kFormsClassificationsMqlsLogging,
              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
-                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
                  ? base::FEATURE_ENABLED_BY_DEFAULT
                  : base::FEATURE_DISABLED_BY_DEFAULT);
 
