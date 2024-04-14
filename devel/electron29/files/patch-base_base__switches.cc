--- base/base_switches.cc.orig	2024-02-21 00:20:30 UTC
+++ base/base_switches.cc
@@ -172,7 +172,7 @@ const char kPackageVersionCode[] = "package-version-co
 const char kPackageVersionCode[] = "package-version-code";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1176772): Remove kEnableCrashpad and IsCrashpadEnabled() when
 // Crashpad is fully enabled on Linux. Indicates that Crashpad should be
 // enabled.
