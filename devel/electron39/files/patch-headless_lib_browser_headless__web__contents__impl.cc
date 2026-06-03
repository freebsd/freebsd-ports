--- headless/lib/browser/headless_web_contents_impl.cc.orig	2025-11-02 19:17:57 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -69,7 +69,7 @@ void UpdatePrefsFromSystemSettings(blink::RendererPref
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
