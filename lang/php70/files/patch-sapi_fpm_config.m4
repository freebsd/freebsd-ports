--- sapi/fpm/config.m4.orig	2015-12-01 16:36:27.000000000 +0300
+++ sapi/fpm/config.m4	2015-12-09 21:34:18.665722795 +0300
@@ -317,14 +317,14 @@
 
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
 
