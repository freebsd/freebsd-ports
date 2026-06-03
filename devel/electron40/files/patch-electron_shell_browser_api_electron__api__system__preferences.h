--- electron/shell/browser/api/electron_api_system_preferences.h.orig	2025-10-27 17:58:27 UTC
+++ electron/shell/browser/api/electron_api_system_preferences.h
@@ -18,7 +18,7 @@
 #include "shell/browser/browser.h"
 #include "shell/browser/browser_observer.h"
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/raw_ptr.h"
 #include "ui/native_theme/native_theme.h"
 #include "ui/native_theme/native_theme_observer.h"
@@ -49,7 +49,7 @@ class SystemPreferences final
 #if BUILDFLAG(IS_WIN)
     ,
       public BrowserObserver
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ,
       public ui::NativeThemeObserver
 #endif
@@ -126,7 +126,7 @@ class SystemPreferences final
   // are running tests on a Mojave machine
   v8::Local<v8::Value> GetEffectiveAppearance(v8::Isolate* isolate);
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // ui::NativeThemeObserver:
   void OnNativeThemeUpdated(ui::NativeTheme* theme) override;
 #endif
@@ -174,7 +174,7 @@ class SystemPreferences final
   // Color/high contrast mode change observer.
   base::CallbackListSubscription hwnd_subscription_;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnNativeThemeUpdatedOnUI();
 
   raw_ptr<ui::NativeTheme> ui_theme_;
