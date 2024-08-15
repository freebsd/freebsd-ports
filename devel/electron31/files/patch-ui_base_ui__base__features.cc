--- ui/base/ui_base_features.cc.orig	2024-06-18 21:44:02 UTC
+++ ui/base/ui_base_features.cc
@@ -245,7 +245,7 @@ BASE_FEATURE(kExperimentalFlingAnimation,
              "ExperimentalFlingAnimation",
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) ||                                   \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD) ||              \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
      !BUILDFLAG(IS_CHROMEOS_LACROS))
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -339,7 +339,7 @@ BASE_FEATURE(kEyeDropper,
 BASE_FEATURE(kEyeDropper,
              "EyeDropper",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
