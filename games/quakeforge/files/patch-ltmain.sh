--- ltmain.sh.orig	Sun Jul 27 16:09:51 2003
+++ ltmain.sh	Sun Jul 27 16:10:01 2003
@@ -1052,7 +1052,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
