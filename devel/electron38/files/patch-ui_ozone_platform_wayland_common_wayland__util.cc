--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2025-06-30 07:04:30 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -421,6 +421,7 @@ void RecordConnectionMetrics(wl_display* display) {
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -446,6 +447,7 @@ void RecordConnectionMetrics(wl_display* display) {
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
