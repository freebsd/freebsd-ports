--- headless/lib/browser/headless_web_contents_impl.cc.orig	2026-03-21 03:23:28 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -74,7 +74,7 @@ void UpdatePrefsFromSystemSettings(blink::RendererPref
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
