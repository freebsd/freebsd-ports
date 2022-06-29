--- chrome/browser/headless/headless_mode_util.cc.orig	2022-05-19 03:45:17 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -9,7 +9,7 @@
 // Native headless is currently available on Linux, Windows and Mac platforms.
 // More platforms will be added later, so avoid function level clutter by
 // providing stub implementations at the end of the file.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 #include <cstdlib>
 #include <vector>
@@ -17,7 +17,7 @@
 #include "base/base_switches.h"
 #include "ui/gfx/switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -51,7 +51,7 @@ void SetUpCommandLine(const base::CommandLine* command
     base::CommandLine::ForCurrentProcess()->AppendSwitch(
         ::switches::kNoErrorDialogs);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Native headless chrome on Linux relies on ozone/headless platform.
   base::CommandLine::ForCurrentProcess()->AppendSwitchASCII(
       ::switches::kOzonePlatform, switches::kHeadless);
