
$FreeBSD$

--- config/ltmain.sh.orig	Sun Jul 14 01:53:50 2002
+++ config/ltmain.sh	Tue Aug 13 18:00:19 2002
@@ -967,6 +967,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -1061,7 +1062,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
