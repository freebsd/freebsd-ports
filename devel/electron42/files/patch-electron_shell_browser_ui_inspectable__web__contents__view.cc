--- electron/shell/browser/ui/inspectable_web_contents_view.cc.orig	2026-06-09 06:05:33 UTC
+++ electron/shell/browser/ui/inspectable_web_contents_view.cc
@@ -220,7 +220,7 @@ void InspectableWebContentsView::SetIsDocked(bool dock
     params.delegate = devtools_window_delegate_;
     params.bounds = inspectable_web_contents()->dev_tools_bounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_role_name = "devtools";
     if (GetDelegate())
       GetDelegate()->GetDevToolsWindowWMClass(&params.wm_class_name,
