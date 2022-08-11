--- extensions/browser/pref_names.h.orig	2022-05-25 04:01:02 UTC
+++ extensions/browser/pref_names.h
@@ -102,7 +102,7 @@ extern const char kToolbar[];
 extern const char kDeletedComponentExtensions[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // A preference for whether Chrome Apps should be allowed. The default depends
 // on the ChromeAppsDeprecation feature flag, and this pref can extend support
 // for Chrome Apps by enterprise policy.
