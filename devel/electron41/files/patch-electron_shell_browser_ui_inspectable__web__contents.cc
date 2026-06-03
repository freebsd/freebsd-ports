--- electron/shell/browser/ui/inspectable_web_contents.cc.orig	2026-04-15 14:10:25 UTC
+++ electron/shell/browser/ui/inspectable_web_contents.cc
@@ -590,7 +590,7 @@ void InspectableWebContents::LoadCompleted() {
           dock_state_ = "right";
         }
       }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       auto* api_web_contents = api::WebContents::From(GetWebContents());
       if (api_web_contents) {
         auto* win =
