--- common/autoconf/generated-configure.sh	Sat Oct 24 06:20:56 2015 -0700
+++ common/autoconf/generated-configure.sh	Wed Jan 20 21:11:45 2016 -0800
@@ -36324,7 +36324,7 @@
     # precompiled headers.
     { $as_echo "$as_me:${as_lineno-$LINENO}: checking if ccache supports precompiled headers" >&5
 $as_echo_n "checking if ccache supports precompiled headers... " >&6; }
-    HAS_GOOD_CCACHE=`($CCACHE --version | head -n 1 | awk '{ split(, a, "."); if (a[1] >= 3 && (a[2] > 1 || (a[2] == 1 && a[3] >= 4))) print "yes"; else print "no"; }') 2> /dev/null`
+    HAS_GOOD_CCACHE=`($CCACHE --version | head -n 1 | awk '{ split($3, a, "."); if (a[1] >= 3 && (a[2] > 1 || (a[2] == 1 && a[3] >= 4))) print "yes"; else print "no"; }') 2> /dev/null`
     if test "x$HAS_GOOD_CCACHE" = xyes; then
       { $as_echo "$as_me:${as_lineno-$LINENO}: result: no, disabling ccache" >&5
 $as_echo "no, disabling ccache" >&6; }
