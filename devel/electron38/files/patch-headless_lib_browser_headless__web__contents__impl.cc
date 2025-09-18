--- headless/lib/browser/headless_web_contents_impl.cc.orig	2025-05-11 11:50:45 UTC
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -70,7 +70,7 @@ void UpdatePrefsFromSystemSettings(blink::RendererPref
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
