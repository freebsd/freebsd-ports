--- src/unix/lwt_unix.ml.orig	2024-02-01 21:33:02 UTC
+++ src/unix/lwt_unix.ml
@@ -1471,6 +1471,7 @@ type socket_bool_option =
   | SO_ACCEPTCONN
   | TCP_NODELAY
   | IPV6_ONLY
+  | SO_REUSEPORT
 
 type socket_int_option =
     Unix.socket_int_option =
