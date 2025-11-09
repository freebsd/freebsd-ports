--- electron/shell/browser/api/electron_api_system_preferences.cc.orig	2025-10-27 17:58:27 UTC
+++ electron/shell/browser/api/electron_api_system_preferences.cc
@@ -11,7 +11,7 @@
 #include "shell/common/gin_helper/handle.h"
 #include "shell/common/node_includes.h"
 #include "ui/gfx/animation/animation.h"
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
 #include "shell/browser/api/electron_api_system_preferences.h"
@@ -27,7 +27,7 @@ SystemPreferences::SystemPreferences() {
 SystemPreferences::SystemPreferences() {
   InitializeWindow();
 }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 SystemPreferences::SystemPreferences()
     : ui_theme_(ui::NativeTheme::GetInstanceForNativeUi()) {
   ui_theme_->AddObserver(this);
@@ -56,7 +56,7 @@ v8::Local<v8::Value> SystemPreferences::GetAnimationSe
   return dict.GetHandle();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string SystemPreferences::GetAccentColor() {
   auto const color = ui_theme_->user_color();
   if (!color.has_value())
