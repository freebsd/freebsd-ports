--- ltmain.sh.orig	Fri Jun 27 19:46:40 2003
+++ ltmain.sh	Fri Jun 27 19:46:52 2003
@@ -1061,7 +1061,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
