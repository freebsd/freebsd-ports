--- config/ltmain.sh.orig	Wed Apr 14 20:10:18 2004
+++ config/ltmain.sh	Wed Apr 14 20:14:14 2004
@@ -1356,7 +1356,11 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+#	 *-*-openbsd* | *-*-freebsd*)
+#	this situation is already managed by the ports tree for
+#	freebsd, so leave it as is(-lc_r is actually needed for machines
+#	built from freebsd-current source in a short life span :)
+	 *-*-openbsd*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
