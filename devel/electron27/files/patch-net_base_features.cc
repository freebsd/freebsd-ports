--- net/base/features.cc.orig	2023-10-25 09:13:47 UTC
+++ net/base/features.cc
@@ -177,7 +177,7 @@ BASE_FEATURE(kCertDualVerificationTrialFeature,
 #if BUILDFLAG(CHROME_ROOT_STORE_OPTIONAL)
 BASE_FEATURE(kChromeRootStoreUsed,
              "ChromeRootStoreUsed",
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
