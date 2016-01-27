--- common/autoconf/build-performance.m4	Sat Oct 24 06:20:56 2015 -0700
+++ common/autoconf/build-performance.m4	Wed Jan 20 21:11:23 2016 -0800
@@ -212,7 +212,7 @@
     # Only use ccache if it is 3.1.4 or later, which supports
     # precompiled headers.
     AC_MSG_CHECKING([if ccache supports precompiled headers])
-    HAS_GOOD_CCACHE=`($CCACHE --version | head -n 1 | awk '{ split($3, a, "."); if (a@<:@1@:>@ >= 3 && (a@<:@2@:>@ > 1 || (a@<:@2@:>@ == 1 && a@<:@3@:>@ >= 4))) print "yes"; else print "no"; }') 2> /dev/null`
+    HAS_GOOD_CCACHE=`($CCACHE --version | head -n 1 | awk '{ split(@S|@3, a, "."); if (a@<:@1@:>@ >= 3 && (a@<:@2@:>@ > 1 || (a@<:@2@:>@ == 1 && a@<:@3@:>@ >= 4))) print "yes"; else print "no"; }') 2> /dev/null`
     if test "x$HAS_GOOD_CCACHE" = xyes; then
       AC_MSG_RESULT([no, disabling ccache])
       CCACHE=
