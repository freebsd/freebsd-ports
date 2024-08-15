--- electron/shell/browser/ui/inspectable_web_contents_view.cc.orig	2024-06-24 09:53:23 UTC
+++ electron/shell/browser/ui/inspectable_web_contents_view.cc
@@ -175,7 +175,7 @@ void InspectableWebContentsView::SetIsDocked(bool dock
     params.delegate = devtools_window_delegate_;
     params.bounds = inspectable_web_contents()->dev_tools_bounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_role_name = "devtools";
     if (GetDelegate())
       GetDelegate()->GetDevToolsWindowWMClass(&params.wm_class_name,
