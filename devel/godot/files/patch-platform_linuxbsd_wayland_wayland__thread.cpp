--- platform/linuxbsd/wayland/wayland_thread.cpp.orig	2026-06-17 18:46:02 UTC
+++ platform/linuxbsd/wayland/wayland_thread.cpp
@@ -1313,7 +1313,7 @@ void WaylandThread::_wl_surface_on_enter(void *data, s
 	WindowState *ws = (WindowState *)data;
 	ERR_FAIL_NULL(ws);
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Window entered output %x.", (size_t)wl_output));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Window entered output %x.", (uint64_t)wl_output));
 
 	ws->wl_outputs.insert(wl_output);
 
@@ -1353,7 +1353,7 @@ void WaylandThread::_wl_surface_on_leave(void *data, s
 
 	ws->wl_outputs.erase(wl_output);
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Window left output %x.\n", (size_t)wl_output));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Window left output %x.\n", (uint64_t)wl_output));
 }
 
 // TODO: Add support to this event.
@@ -1419,7 +1419,7 @@ void WaylandThread::_wl_output_on_done(void *data, str
 
 	ss->wayland_thread->_update_scale(ss->data.scale);
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x done.", (size_t)wl_output));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x done.", (uint64_t)wl_output));
 }
 
 void WaylandThread::_wl_output_on_scale(void *data, struct wl_output *wl_output, int32_t factor) {
@@ -1428,7 +1428,7 @@ void WaylandThread::_wl_output_on_scale(void *data, st
 
 	ss->pending_data.scale = factor;
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x scale %d", (size_t)wl_output, factor));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x scale %d", (uint64_t)wl_output, factor));
 }
 
 void WaylandThread::_wl_output_on_name(void *data, struct wl_output *wl_output, const char *name) {
