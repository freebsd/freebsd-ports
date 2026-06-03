--- electron/shell/browser/ui/inspectable_web_contents.cc.orig	2026-05-27 13:37:43 UTC
+++ electron/shell/browser/ui/inspectable_web_contents.cc
@@ -589,7 +589,7 @@ void InspectableWebContents::LoadCompleted() {
           dock_state_ = "right";
         }
       }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       auto* api_web_contents = api::WebContents::From(GetWebContents());
       if (api_web_contents) {
         auto* win =
