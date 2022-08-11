--- extensions/browser/pref_names.h.orig	2022-05-19 05:17:42 UTC
+++ extensions/browser/pref_names.h
@@ -101,7 +101,7 @@ extern const char kToolbar[];
 // uninstalled/removed and should not be reloaded.
 extern const char kDeletedComponentExtensions[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A preference for whether Chrome Apps should be allowed. The default depends
 // on the ChromeAppsDeprecation feature flag, and this pref can extend support
 // for Chrome Apps by enterprise policy.
