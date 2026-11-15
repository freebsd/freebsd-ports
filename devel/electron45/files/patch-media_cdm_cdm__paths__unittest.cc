--- media/cdm/cdm_paths_unittest.cc.orig	2025-04-22 20:15:27 UTC
+++ media/cdm/cdm_paths_unittest.cc
@@ -26,7 +26,7 @@ const char kComponentPlatform[] =
     "win";
 #elif BUILDFLAG(IS_CHROMEOS)
     "cros";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "linux";
 #elif BUILDFLAG(IS_FUCHSIA)
     "fuchsia";
