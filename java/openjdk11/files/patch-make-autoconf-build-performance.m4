--- make/autoconf/build-performance.m4
+++ make/autoconf/build-performance.m4
@@ -41,6 +41,10 @@ AC_DEFUN([BPERF_CHECK_CORES],
     # Looks like a MacOSX system
     NUM_CORES=`/usr/sbin/sysctl -n hw.ncpu`
     FOUND_CORES=yes
+  elif test -x /sbin/sysctl; then
+    # Looks like a BSD system
+    NUM_CORES=`/sbin/sysctl -n hw.ncpu`
+    FOUND_CORES=yes
   elif test "x$OPENJDK_BUILD_OS" = xaix ; then
     NUM_CORES=`/usr/sbin/prtconf | grep "^Number Of Processors" | awk '{ print [$]4 }'`
     FOUND_CORES=yes
