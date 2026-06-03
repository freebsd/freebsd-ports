--- electron/shell/browser/api/electron_api_system_preferences.cc.orig	2026-01-15 18:39:20 UTC
+++ electron/shell/browser/api/electron_api_system_preferences.cc
@@ -10,7 +10,7 @@
 #include "shell/common/gin_helper/handle.h"
 #include "shell/common/node_includes.h"
 #include "ui/gfx/animation/animation.h"
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
 #include "shell/browser/api/electron_api_system_preferences.h"
@@ -26,7 +26,7 @@ SystemPreferences::SystemPreferences() {
 SystemPreferences::SystemPreferences() {
   InitializeWindow();
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 SystemPreferences::SystemPreferences()
     : ui_theme_(ui::NativeTheme::GetInstanceForNativeUi()) {
   ui_theme_->AddObserver(this);
@@ -55,7 +55,7 @@ v8::Local<v8::Value> SystemPreferences::GetAnimationSe
   return dict.GetHandle();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string SystemPreferences::GetAccentColor() {
   auto const color = ui_theme_->user_color();
   if (!color.has_value())
