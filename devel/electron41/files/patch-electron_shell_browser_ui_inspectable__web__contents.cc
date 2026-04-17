--- electron/shell/browser/ui/inspectable_web_contents.cc.orig	2026-04-07 01:35:50 UTC
+++ electron/shell/browser/ui/inspectable_web_contents.cc
@@ -575,7 +575,7 @@ void InspectableWebContents::LoadCompleted() {
         dock_state_ = "right";
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto* api_web_contents = api::WebContents::From(GetWebContents());
     if (api_web_contents) {
       auto* win =
