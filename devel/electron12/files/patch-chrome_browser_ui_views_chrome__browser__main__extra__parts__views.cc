--- chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -38,7 +38,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -48,7 +48,7 @@
 #include "chrome/grit/generated_resources.h"
 #include "content/public/common/content_switches.h"
 #include "ui/base/l10n/l10n_util.h"
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 // This connector is used in ui_devtools's TracingAgent to hook up with the
 // tracing service.
@@ -120,7 +120,7 @@ void ChromeBrowserMainExtraPartsViews::PreProfileInit(
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // On the Linux desktop, we want to prevent the user from logging in as root,
   // so that we don't destroy the profile. Now that we have some minimal ui
   // initialized, check to see if we're running as root and bail if we are.
@@ -151,7 +151,7 @@ void ChromeBrowserMainExtraPartsViews::PreProfileInit(
   base::RunLoop().RunUntilIdle();
 
   exit(EXIT_FAILURE);
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 }
 
 void ChromeBrowserMainExtraPartsViews::PostBrowserStart() {
