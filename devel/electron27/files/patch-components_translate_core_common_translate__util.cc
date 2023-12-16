--- components/translate/core/common/translate_util.cc.orig	2023-10-19 19:58:21 UTC
+++ components/translate/core/common/translate_util.cc
@@ -21,7 +21,7 @@ const char kSecurityOrigin[] = "https://translate.goog
 BASE_FEATURE(kTFLiteLanguageDetectionEnabled,
              "TFLiteLanguageDetectionEnabled",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
