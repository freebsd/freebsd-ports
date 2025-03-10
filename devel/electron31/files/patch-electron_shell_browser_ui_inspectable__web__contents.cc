--- electron/shell/browser/ui/inspectable_web_contents.cc.orig	2024-10-16 13:04:26 UTC
+++ electron/shell/browser/ui/inspectable_web_contents.cc
@@ -556,7 +556,7 @@ void InspectableWebContents::LoadCompleted() {
           prefs.FindString("currentDockState");
       base::RemoveChars(*current_dock_state, "\"", &dock_state_);
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     auto* api_web_contents = api::WebContents::From(GetWebContents());
     if (api_web_contents) {
       auto* win =
