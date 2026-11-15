--- headless/lib/browser/headless_web_contents_impl.cc.orig	2026-10-30 11:54:04 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -79,7 +79,7 @@ void UpdatePrefsFromSystemSettings(blink::RendererPref
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
