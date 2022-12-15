--- ui/gl/gl_features.cc.orig	2022-07-22 17:30:31 UTC
+++ ui/gl/gl_features.cc
@@ -85,7 +85,7 @@ const base::Feature kDefaultPassthroughCommandDecoder 
   "DefaultPassthroughCommandDecoder",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) ||     \
     (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
