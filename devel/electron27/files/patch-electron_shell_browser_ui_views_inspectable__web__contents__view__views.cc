--- electron/shell/browser/ui/views/inspectable_web_contents_view_views.cc.orig	2024-02-28 05:54:17 UTC
+++ electron/shell/browser/ui/views/inspectable_web_contents_view_views.cc
@@ -183,7 +183,7 @@ void InspectableWebContentsViewViews::SetIsDocked(bool
     params.delegate = devtools_window_delegate_;
     params.bounds = inspectable_web_contents()->dev_tools_bounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_role_name = "devtools";
     if (GetDelegate())
       GetDelegate()->GetDevToolsWindowWMClass(&params.wm_class_name,
