--- sapi/fpm/config.m4.orig	2013-12-10 19:32:43.000000000 +0000
+++ sapi/fpm/config.m4	2013-12-13 21:55:54.457235637 +0000
@@ -317,7 +317,7 @@ AC_DEFUN([AC_FPM_LQ],
 
   AC_MSG_CHECKING([for TCP_INFO])
 
-  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; int x = TCP_INFO;], [
+  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; ti.tcpi_sacked = 0; int x = TCP_INFO;], [
     have_lq=tcp_info
     AC_MSG_RESULT([yes])
   ], [
@@ -338,7 +338,7 @@ AC_DEFUN([AC_FPM_LQ],
       AC_MSG_RESULT([no])
     ])
 
-    if test "$have_lq" = "tcp_info"; then
+    if test "$have_lq" = "so_listenq"; then
       AC_DEFINE([HAVE_LQ_SO_LISTENQ], 1, [do we have SO_LISTENQxxx?])
     fi
   fi
