--- components/optimization_guide/core/feature_registry/feature_registration.cc.orig	2025-10-21 20:19:54 UTC
+++ components/optimization_guide/core/feature_registry/feature_registration.cc
@@ -65,7 +65,7 @@ BASE_FEATURE(kFormsClassificationsMqlsLogging,
 
 BASE_FEATURE(kFormsClassificationsMqlsLogging,
              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
-                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
                  ? base::FEATURE_ENABLED_BY_DEFAULT
                  : base::FEATURE_DISABLED_BY_DEFAULT);
 
