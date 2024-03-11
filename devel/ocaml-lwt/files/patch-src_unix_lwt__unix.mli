--- src/unix/lwt_unix.mli.orig	2016-04-25 14:32:43 UTC
+++ src/unix/lwt_unix.mli
@@ -806,6 +806,7 @@ type socket_bool_option =
   | SO_ACCEPTCONN
   | TCP_NODELAY
   | IPV6_ONLY
+  | SO_REUSEPORT
 
 type socket_int_option =
     Unix.socket_int_option =
