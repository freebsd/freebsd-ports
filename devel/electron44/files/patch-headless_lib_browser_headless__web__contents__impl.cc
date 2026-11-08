--- headless/lib/browser/headless_web_contents_impl.cc.orig	2026-09-01 23:50:56 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -76,7 +76,7 @@ void UpdatePrefsFromSystemSettings(blink::RendererPref
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
