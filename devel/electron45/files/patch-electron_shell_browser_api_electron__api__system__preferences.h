--- electron/shell/browser/api/electron_api_system_preferences.h.orig	2026-10-26 21:12:45 UTC
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
@@ -45,7 +45,7 @@ class SystemPreferences final
 #if BUILDFLAG(IS_WIN)
     ,
       public BrowserObserver
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     ,
       public ui::NativeThemeObserver
 #endif
@@ -130,7 +130,7 @@ class SystemPreferences final
   // are running tests on a Mojave machine
   v8::Local<v8::Value> GetEffectiveAppearance(v8::Isolate* isolate);
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // ui::NativeThemeObserver:
   void OnNativeThemeUpdated(ui::NativeTheme* theme) override;
 #endif
@@ -165,13 +165,13 @@ class SystemPreferences final
   base::CallbackListSubscription hwnd_subscription_;
   base::CallbackListSubscription accent_color_subscription_;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnNativeThemeUpdatedOnUI();
 
   raw_ptr<ui::NativeTheme> ui_theme_;
   std::string current_accent_color_;
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gin::WeakCellFactory<SystemPreferences> weak_factory_{this};
 #endif
 };
