--- chrome/browser/first_run/first_run_internal.h.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/first_run/first_run_internal.h
@@ -54,7 +54,7 @@ FirstRunState DetermineFirstRunState(bool has_sentinel
                                      bool force_first_run,
                                      bool no_first_run);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // For testing, forces the first run dialog to either be shown or not. If not
 // called, the decision to show the dialog or not will be made by Chrome based
 // on a number of factors (such as install type, whether it's a Chrome-branded
