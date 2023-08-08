--- extensions/browser/pref_names.h.orig	2023-02-01 18:43:20 UTC
+++ extensions/browser/pref_names.h
@@ -103,7 +103,7 @@ extern const char kStorageGarbageCollect[];
 extern const char kDeletedComponentExtensions[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // A preference for whether Chrome Apps should be allowed. The default depends
 // on the ChromeAppsDeprecation feature flag, and this pref can extend support
 // for Chrome Apps by enterprise policy.
