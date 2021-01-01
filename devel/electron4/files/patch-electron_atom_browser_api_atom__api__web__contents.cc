--- electron/atom/browser/api/atom_api_web_contents.cc.orig	2019-06-19 18:06:58 UTC
+++ electron/atom/browser/api/atom_api_web_contents.cc
@@ -95,7 +95,7 @@
 #include "ui/aura/window.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "content/public/common/renderer_preferences.h"
 #include "ui/gfx/font_render_params.h"
 #endif
@@ -413,7 +413,7 @@ void WebContents::InitWithSessionAndOptions(v8::Isolat
   auto* prefs = web_contents->GetMutableRendererPrefs();
   prefs->accept_languages = g_browser_process->GetApplicationLocale();
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Update font settings.
   CR_DEFINE_STATIC_LOCAL(
       const gfx::FontRenderParams, params,
