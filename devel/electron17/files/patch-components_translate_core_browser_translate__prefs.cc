--- components/translate/core/browser/translate_prefs.cc.orig	2022-05-11 07:16:51 UTC
+++ components/translate/core/browser/translate_prefs.cc
@@ -905,7 +905,7 @@ bool TranslatePrefs::CanTranslateLanguage(
 bool TranslatePrefs::IsDetailedLanguageSettingsEnabled() {
 #if defined(OS_ANDROID)
   return base::FeatureList::IsEnabled(language::kDetailedLanguageSettings);
-#elif defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#elif defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
   return base::FeatureList::IsEnabled(
       language::kDesktopDetailedLanguageSettings);
 #else
