--- electron/shell/browser/api/electron_api_system_preferences.h.orig	2026-09-29 23:27:57 UTC
+++ electron/shell/browser/api/electron_api_system_preferences.h
@@ -19,7 +19,7 @@
 #include "shell/browser/browser.h"
 #include "shell/browser/browser_observer.h"
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/raw_ptr.h"
 #include "ui/native_theme/native_theme.h"
 #include "ui/native_theme/native_theme_observer.h"
@@ -50,7 +50,7 @@ class SystemPreferences final
 #if BUILDFLAG(IS_WIN)
     ,
       public BrowserObserver
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ,
       public ui::NativeThemeObserver
 #endif
@@ -127,7 +127,7 @@ class SystemPreferences final
   // are running tests on a Mojave machine
   v8::Local<v8::Value> GetEffectiveAppearance(v8::Isolate* isolate);
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // ui::NativeThemeObserver:
   void OnNativeThemeUpdated(ui::NativeTheme* theme) override;
 #endif
@@ -159,7 +159,7 @@ class SystemPreferences final
   base::CallbackListSubscription hwnd_subscription_;
   base::CallbackListSubscription accent_color_subscription_;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnNativeThemeUpdatedOnUI();
 
   raw_ptr<ui::NativeTheme> ui_theme_;
