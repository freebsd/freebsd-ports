--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -31,7 +31,7 @@ void AppearanceHandler::RegisterMessages() {
                           base::Unretained(this)));
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseSystemTheme,
@@ -45,7 +45,7 @@ void AppearanceHandler::HandleUseDefaultTheme(base::Va
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 void AppearanceHandler::HandleUseSystemTheme(base::Value::ConstListView args) {
   if (profile_->IsChild())
     NOTREACHED();
