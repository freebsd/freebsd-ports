--- config/ltmain.sh.orig	Sat Feb 14 16:37:52 2004
+++ config/ltmain.sh	Sat Feb 14 16:39:37 2004
@@ -1061,7 +1061,11 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+#	 *-*-openbsd* | *-*-freebsd*)
+#	this situation is already managed by the ports tree for
+#	freebsd, so leave it as is(-lc_r is actually needed for machines
+#	built from freebsd-current source in a short life span :)
+	  *-*-openbsd*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
