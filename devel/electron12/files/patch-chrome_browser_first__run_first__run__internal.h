--- chrome/browser/first_run/first_run_internal.h.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/first_run/first_run_internal.h
@@ -58,14 +58,13 @@ FirstRunState DetermineFirstRunState(bool has_sentinel
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_MAC) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(OS_MAC) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
 // build, etc).
 void ForceFirstRunDialogShownForTesting(bool shown);
-#endif  // defined(OS_MAC) || (defined(OS_LINUX) ||
-        // BUILDFLAG(IS_CHROMEOS_LACROS))
+#endif  // defined(OS_MAC) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 
 }  // namespace internal
 }  // namespace first_run
