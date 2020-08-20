--- lib/erl_interface/src/misc/ei_portio.h.orig	2020-08-20 15:20:59 UTC
+++ lib/erl_interface/src/misc/ei_portio.h
@@ -47,7 +47,7 @@ int ei_writev_fill_ctx_t__(ei_socket_callbacks *cbs, v
 int ei_socket_callbacks_have_writev__(ei_socket_callbacks *cbs);
 #endif
 
-ei_socket_callbacks ei_default_socket_callbacks;
+extern ei_socket_callbacks ei_default_socket_callbacks;
 
 #define EI_FD_AS_CTX__(FD)                                              \
     ((void *) (long) (FD))
