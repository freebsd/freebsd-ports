--- config.m4.orig	2016-01-12 12:40:08 UTC
+++ config.m4
@@ -59,9 +59,11 @@ if test "$PHP_RRD" != "no"; then
   LDFLAGS="$LDFLAGS -L$RRDTOOL_LIBDIR"
 
   dnl rrd_graph_v is available in 1.3.0+
+  rrd_graph_c=""
   PHP_CHECK_FUNC(rrd_graph_v, rrd)
-  if test "$ac_cv_func_rrd_graph_v" != yes; then
-    AC_MSG_ERROR([rrd lib version seems older than 1.3.0, update to 1.3.0+])
+  if test "$ac_cv_func_rrd_graph_v" == yes; then
+    AC_DEFINE(HAVE_RRD_GRAPH, 1, [ ])
+    rrd_graph_c="rrd_graph.c"
   fi
 
   dnl rrd_lastupdate_r available in 1.4.0+
@@ -72,6 +74,6 @@ if test "$PHP_RRD" != "no"; then
 
   LDFLAGS=$old_LDFLAGS
 
-  PHP_NEW_EXTENSION(rrd, rrd.c rrd_graph.c rrd_create.c rrd_update.c rrd_info.c, $ext_shared)
+  PHP_NEW_EXTENSION(rrd, rrd.c $rrd_graph_c rrd_create.c rrd_update.c rrd_info.c, $ext_shared)
   PHP_SUBST(RRD_SHARED_LIBADD)
 fi
