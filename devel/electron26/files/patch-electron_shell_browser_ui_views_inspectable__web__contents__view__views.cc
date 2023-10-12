--- electron/shell/browser/ui/views/inspectable_web_contents_view_views.cc.orig	2023-10-10 23:44:27 UTC
+++ electron/shell/browser/ui/views/inspectable_web_contents_view_views.cc
@@ -184,7 +184,7 @@ void InspectableWebContentsViewViews::SetIsDocked(bool
     params.delegate = devtools_window_delegate_;
     params.bounds = inspectable_web_contents()->GetDevToolsBounds();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_role_name = "devtools";
     if (GetDelegate())
       GetDelegate()->GetDevToolsWindowWMClass(&params.wm_class_name,
