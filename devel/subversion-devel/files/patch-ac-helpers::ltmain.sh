--- ac-helpers/ltmain.sh.orig	2004-10-22 22:13:13.000000000 +0400
+++ ac-helpers/ltmain.sh	2004-11-05 11:30:39.328125000 +0300
@@ -1061,7 +1061,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
