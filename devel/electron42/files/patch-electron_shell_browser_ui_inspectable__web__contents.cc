--- electron/shell/browser/ui/inspectable_web_contents.cc.orig	2026-06-29 04:13:24 UTC
+++ electron/shell/browser/ui/inspectable_web_contents.cc
@@ -593,7 +593,7 @@ void InspectableWebContents::LoadCompleted() {
           dock_state_ = "right";
         }
       }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       auto* api_web_contents = api::WebContents::From(GetWebContents());
       if (api_web_contents) {
         auto* win =
