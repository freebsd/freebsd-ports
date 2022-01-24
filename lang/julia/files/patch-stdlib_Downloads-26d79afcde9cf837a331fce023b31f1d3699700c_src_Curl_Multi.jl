--- stdlib/Downloads-26d79afcde9cf837a331fce023b31f1d3699700c/src/Curl/Multi.jl.orig	2021-10-26 22:48:36 UTC
+++ stdlib/Downloads-26d79afcde9cf837a331fce023b31f1d3699700c/src/Curl/Multi.jl
@@ -142,12 +142,7 @@ function timer_callback(
 )::Cint
     multi = unsafe_pointer_to_objref(multi_p)::Multi
     @assert multi_h == multi.handle
-    if timeout_ms == 0
-        lock(multi.lock) do
-            @check curl_multi_socket_action(multi.handle, CURL_SOCKET_TIMEOUT, 0)
-            check_multi_info(multi)
-        end
-    elseif timeout_ms >= 0
+    if timeout_ms >= 0
         timeout_cb = @cfunction(timeout_callback, Cvoid, (Ptr{Cvoid},))
         uv_timer_start(multi.timer, timeout_cb, max(1, timeout_ms), 0)
     elseif timeout_ms == -1
