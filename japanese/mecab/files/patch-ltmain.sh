--- ltmain.sh.orig	Mon Oct 20 21:58:16 2003
+++ ltmain.sh	Mon Oct 20 21:58:39 2003
@@ -1075,7 +1075,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
