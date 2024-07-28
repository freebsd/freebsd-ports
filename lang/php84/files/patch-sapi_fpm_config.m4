--- sapi/fpm/config.m4.orig	2024-07-02 13:43:13 UTC
+++ sapi/fpm/config.m4
@@ -271,7 +271,7 @@ AC_DEFUN([PHP_FPM_LQ],
     AC_MSG_RESULT([no])
   ])
 
-  if test "$have_lq" = "tcp_info"; then
+  if test "$have_lq" = "so_listenq"; then
     AC_DEFINE([HAVE_LQ_TCP_INFO], 1, [do we have TCP_INFO?])
   fi
 
