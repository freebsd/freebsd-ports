--- chrome/browser/browser_features.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/browser_features.cc
@@ -29,7 +29,7 @@ const base::Feature kColorProviderRedirectionForThemeP
 // the browser exits.
 const base::Feature kDestroyProfileOnBrowserClose {
   "DestroyProfileOnBrowserClose",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 };
 #else
