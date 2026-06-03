--- platform/linuxbsd/wayland/wayland_thread.cpp.orig	2025-10-13 19:05:40 UTC
+++ platform/linuxbsd/wayland/wayland_thread.cpp
@@ -95,7 +95,7 @@ Vector<uint8_t> WaylandThread::_read_fd(int fd) {
 			break;
 		}
 
-		DEBUG_LOG_WAYLAND_THREAD(vformat("Read chunk of %d bytes.", last_bytes_read));
+		DEBUG_LOG_WAYLAND_THREAD(vformat("Read chunk of %d bytes.", (uint64_t)last_bytes_read));
 
 		bytes_read += last_bytes_read;
 
@@ -1197,7 +1197,7 @@ void WaylandThread::_wl_surface_on_enter(void *data, s
 	WindowState *ws = (WindowState *)data;
 	ERR_FAIL_NULL(ws);
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Window entered output %x.", (size_t)wl_output));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Window entered output %x.", (uint64_t)wl_output));
 
 	ws->wl_outputs.insert(wl_output);
 
@@ -1248,7 +1248,7 @@ void WaylandThread::_wl_surface_on_leave(void *data, s
 
 	ws->wl_outputs.erase(wl_output);
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Window left output %x.\n", (size_t)wl_output));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Window left output %x.\n", (uint64_t)wl_output));
 }
 
 // TODO: Add support to this event.
@@ -1310,7 +1310,7 @@ void WaylandThread::_wl_output_on_done(void *data, str
 
 	ss->wayland_thread->_update_scale(ss->data.scale);
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x done.", (size_t)wl_output));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x done.", (uint64_t)wl_output));
 }
 
 void WaylandThread::_wl_output_on_scale(void *data, struct wl_output *wl_output, int32_t factor) {
@@ -1319,7 +1319,7 @@ void WaylandThread::_wl_output_on_scale(void *data, st
 
 	ss->pending_data.scale = factor;
 
-	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x scale %d", (size_t)wl_output, factor));
+	DEBUG_LOG_WAYLAND_THREAD(vformat("Output %x scale %d", (uint64_t)wl_output, factor));
 }
 
 void WaylandThread::_wl_output_on_name(void *data, struct wl_output *wl_output, const char *name) {
@@ -2509,7 +2509,7 @@ void WaylandThread::_wl_data_source_on_send(void *data
 		}
 
 		if (written_bytes > 0) {
-			DEBUG_LOG_WAYLAND_THREAD(vformat("Clipboard: sent %d bytes.", written_bytes));
+			DEBUG_LOG_WAYLAND_THREAD(vformat("Clipboard: sent %d bytes.", (uint64_t)written_bytes));
 		} else if (written_bytes == 0) {
 			DEBUG_LOG_WAYLAND_THREAD("Clipboard: no bytes sent.");
 		} else {
@@ -2697,7 +2697,7 @@ void WaylandThread::_wp_primary_selection_source_on_se
 		}
 
 		if (written_bytes > 0) {
-			DEBUG_LOG_WAYLAND_THREAD(vformat("Clipboard: sent %d bytes.", written_bytes));
+			DEBUG_LOG_WAYLAND_THREAD(vformat("Clipboard: sent %d bytes.", (uint64_t)written_bytes));
 		} else if (written_bytes == 0) {
 			DEBUG_LOG_WAYLAND_THREAD("Clipboard: no bytes sent.");
 		} else {
