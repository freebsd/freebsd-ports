--- base/base_switches.cc.orig	2023-05-25 00:41:37 UTC
+++ base/base_switches.cc
@@ -167,7 +167,7 @@ const char kForceFieldTrialParams[] = "force-fieldtria
 
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1176772): Remove kEnableCrashpad and IsCrashpadEnabled() when
 // Crashpad is fully enabled on Linux. Indicates that Crashpad should be
 // enabled.
