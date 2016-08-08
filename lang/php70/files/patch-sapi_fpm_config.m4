--- sapi/fpm/config.m4.orig	2016-07-20 13:11:36 UTC
+++ sapi/fpm/config.m4
@@ -317,14 +317,14 @@ AC_DEFUN([AC_FPM_LQ],
 
   AC_MSG_CHECKING([for TCP_INFO])
 
-  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; int x = TCP_INFO;], [
+  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; ti.tcpi_sacked = 0; int x = TCP_INFO;], [
     have_lq=tcp_info
     AC_MSG_RESULT([yes])
   ], [
     AC_MSG_RESULT([no])
   ])
 
-  if test "$have_lq" = "tcp_info"; then
+  if test "$have_lq" = "so_listenq"; then
     AC_DEFINE([HAVE_LQ_TCP_INFO], 1, [do we have TCP_INFO?])
   fi
 
