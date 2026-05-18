--- ui/views/widget/widget.h.orig	2026-05-12 08:53:52 UTC
+++ ui/views/widget/widget.h
@@ -491,7 +491,7 @@ class VIEWS_EXPORT Widget : public internal::NativeWid
     bool dont_show_in_taskbar = false;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only used by X11, for root level windows. Specifies the res_name and
     // res_class fields, respectively, of the WM_CLASS window property. Controls
     // window grouping and desktop file matching in Linux window managers.
