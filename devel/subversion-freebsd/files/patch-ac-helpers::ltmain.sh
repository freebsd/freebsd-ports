--- ac-helpers/ltmain.sh.orig	Thu Oct 23 17:15:47 2003
+++ ac-helpers/ltmain.sh	Tue Nov 11 15:04:17 2003
@@ -1072,7 +1072,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;

