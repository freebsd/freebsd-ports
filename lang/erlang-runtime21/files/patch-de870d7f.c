diff --git a/lib/erl_interface/src/misc/ei_portio.h b/lib/erl_interface/src/misc/ei_portio.h
index 84ebc5039ab..5172d085b40 100644
--- lib/erl_interface/src/misc/ei_portio.h
+++ lib/erl_interface/src/misc/ei_portio.h
@@ -47,7 +47,7 @@ int ei_writev_fill_ctx_t__(ei_socket_callbacks *cbs, void *ctx, const struct iov
 int ei_socket_callbacks_have_writev__(ei_socket_callbacks *cbs);
 #endif
 
-ei_socket_callbacks ei_default_socket_callbacks;
+extern ei_socket_callbacks ei_default_socket_callbacks;
 
 #define EI_FD_AS_CTX__(FD)                                              \
     ((void *) (long) (FD))
