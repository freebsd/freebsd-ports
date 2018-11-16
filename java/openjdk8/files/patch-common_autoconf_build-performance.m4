--- common/autoconf/build-performance.m4.orig
+++ common/autoconf/build-performance.m4
@@ -213,7 +213,7 @@ AC_DEFUN([BPERF_SETUP_CCACHE_USAGE],
     # precompiled headers.
     AC_MSG_CHECKING([if ccache supports precompiled headers])
     HAS_GOOD_CCACHE=`($CCACHE --version | head -n 1 | awk '{ split(@S|@3, a, "."); if (a@<:@1@:>@ >= 3 && (a@<:@2@:>@ > 1 || (a@<:@2@:>@ == 1 && a@<:@3@:>@ >= 4))) print "yes"; else print "no"; }') 2> /dev/null`
-    if test "x$HAS_GOOD_CCACHE" = xyes; then
+    if test "x$HAS_GOOD_CCACHE" != xyes; then
       AC_MSG_RESULT([no, disabling ccache])
       CCACHE=
     else
