--- electron/shell/browser/api/electron_api_system_preferences.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_system_preferences.cc
@@ -16,7 +16,7 @@
 #include "v8/include/cppgc/allocation.h"
 #include "v8/include/cppgc/persistent.h"
 #include "v8/include/v8-cppgc.h"
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/browser/browser_thread.h"
 #include "shell/browser/api/electron_api_system_preferences.h"
 #include "shell/common/color_util.h"
@@ -32,7 +32,7 @@ SystemPreferences::SystemPreferences(v8::Isolate* isol
   gin::PerIsolateData::From(isolate)->AddDisposeObserver(this);
   InitializeWindow();
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 SystemPreferences::SystemPreferences(v8::Isolate* isolate)
     : ui_theme_(ui::NativeTheme::GetInstanceForNativeUi()) {
   gin::PerIsolateData::From(isolate)->AddDisposeObserver(this);
@@ -51,7 +51,7 @@ void SystemPreferences::OnBeforeMicrotasksRunnerDispos
   Dispose();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SystemPreferences::Dispose() {
   ui_theme_->RemoveObserver(this);
   weak_factory_.Invalidate();
@@ -74,7 +74,7 @@ v8::Local<v8::Value> SystemPreferences::GetAnimationSe
   return dict.GetHandle();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string SystemPreferences::GetAccentColor() {
   auto const color = ui_theme_->user_color();
   if (!color.has_value())
@@ -174,7 +174,7 @@ void SystemPreferences::Trace(cppgc::Visitor* visitor)
 
 void SystemPreferences::Trace(cppgc::Visitor* visitor) const {
   gin::Wrappable<SystemPreferences>::Trace(visitor);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   visitor->Trace(weak_factory_);
 #endif
 }
