--- sapi/fpm/config.m4.orig	2011-06-26 17:48:11.000000000 +0200
+++ sapi/fpm/config.m4	2011-11-18 11:05:21.000000000 +0100
@@ -312,7 +312,7 @@
 
   AC_MSG_CHECKING([for TCP_INFO])
 
-  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; int x = TCP_INFO;], [
+  AC_TRY_COMPILE([ #include <netinet/tcp.h> ], [struct tcp_info ti; ti.tcpi_sacked = 0; int x = TCP_INFO;], [
     have_lq=tcp_info
     AC_MSG_RESULT([yes])
   ], [
@@ -333,7 +333,7 @@
       AC_MSG_RESULT([no])
     ])
 
-    if test "$have_lq" = "tcp_info"; then
+    if test "$have_lq" = "so_listenq"; then
       AC_DEFINE([HAVE_LQ_SO_LISTENQ], 1, [do we have SO_LISTENQxxx?])
     fi
   fi
