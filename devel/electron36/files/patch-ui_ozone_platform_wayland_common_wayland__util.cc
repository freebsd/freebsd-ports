--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2025-04-22 20:15:27 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -424,6 +424,7 @@ void RecordConnectionMetrics(wl_display* display) {
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -449,6 +450,7 @@ void RecordConnectionMetrics(wl_display* display) {
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
