--- docs/src/udp.rst.orig	2020-04-15 16:31:21 UTC
+++ docs/src/udp.rst
@@ -42,11 +42,6 @@ Data types
             * any traffic, in effect "stealing" the port from the previous listener.
             */
             UV_UDP_REUSEADDR = 4
-            /*
-             * Indicates that the message was received by recvmmsg, so the buffer provided
-             * must not be freed by the recv_cb callback.
-             */
-            UV_UDP_MMSG_CHUNK = 8
         };
 
 .. c:type:: void (*uv_udp_send_cb)(uv_udp_send_t* req, int status)
@@ -67,18 +62,13 @@ Data types
     * `buf`: :c:type:`uv_buf_t` with the received data.
     * `addr`: ``struct sockaddr*`` containing the address of the sender.
       Can be NULL. Valid for the duration of the callback only.
-    * `flags`: One or more or'ed UV_UDP_* constants.
+    * `flags`: One or more or'ed UV_UDP_* constants. Right now only
+      ``UV_UDP_PARTIAL`` is used.
 
     The callee is responsible for freeing the buffer, libuv does not reuse it.
     The buffer may be a null buffer (where `buf->base` == NULL and `buf->len` == 0)
     on error.
 
-    When using :man:`recvmmsg(2)`, chunks will have the `UV_UDP_MMSG_CHUNK` flag set,
-    those must not be freed. There will be a final callback with `nread` set to 0,
-    `addr` set to NULL and the buffer pointing at the initially allocated data with
-    the `UV_UDP_MMSG_CHUNK` flag cleared. This is a good chance for the callee to
-    free the provided buffer.
-
     .. note::
         The receive callback will be called with `nread` == 0 and `addr` == NULL when there is
         nothing to read, and with `nread` == 0 and `addr` != NULL when an empty UDP packet is
@@ -376,10 +366,6 @@ API
 
     :returns: 0 on success, or an error code < 0 on failure.
 
-    .. versionchanged:: 1.35.0 added support for :man:`recvmmsg(2)` on supported platforms).
-                        The use of this feature requires a buffer larger than
-                        2 * 64KB to be passed to `alloc_cb`.
-
 .. c:function:: int uv_udp_recv_stop(uv_udp_t* handle)
 
     Stop listening for incoming datagrams.
@@ -402,3 +388,4 @@ API
     .. versionadded:: 1.19.0
 
 .. seealso:: The :c:type:`uv_handle_t` API functions also apply.
+
