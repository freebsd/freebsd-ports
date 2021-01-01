--- chrome/browser/first_run/first_run_internal.h.orig	2019-12-12 12:39:10 UTC
+++ chrome/browser/first_run/first_run_internal.h
@@ -64,13 +64,13 @@ FirstRunState DetermineFirstRunState(bool has_sentinel
                                      bool force_first_run,
                                      bool no_first_run);
 
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
 // build, etc).
 void ForceFirstRunDialogShownForTesting(bool shown);
-#endif  // defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#endif  // defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 }  // namespace internal
 }  // namespace first_run
