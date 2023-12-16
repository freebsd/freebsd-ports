--- chrome/browser/headless/headless_mode_util.cc.orig	2023-10-19 19:58:04 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -10,12 +10,12 @@
 // New headless mode is available on Linux, Windows and Mac platforms.
 // More platforms will be added later, so avoid function level clutter
 // by providing stub implementations at the end of the file.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 #include "base/base_switches.h"
 #include "chrome/common/chrome_switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gl/gl_switches.h"               // nogncheck
 #include "ui/ozone/public/ozone_switches.h"  // nogncheck
 #endif  // BUILDFLAG(IS_LINUX)
@@ -73,7 +73,7 @@ void SetUpCommandLine(const base::CommandLine* command
         ::switches::kNoErrorDialogs);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Headless mode on Linux relies on ozone/headless platform.
   base::CommandLine::ForCurrentProcess()->AppendSwitchASCII(
       ::switches::kOzonePlatform, switches::kHeadless);
