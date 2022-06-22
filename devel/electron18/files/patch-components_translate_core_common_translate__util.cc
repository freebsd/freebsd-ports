--- components/translate/core/common/translate_util.cc.orig	2022-05-19 03:45:26 UTC
+++ components/translate/core/common/translate_util.cc
@@ -34,7 +34,7 @@ const base::Feature kTranslateSubFrames{"TranslateSubF
 const base::Feature kTFLiteLanguageDetectionEnabled{
   "TFLiteLanguageDetectionEnabled",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
