--- config/ltmain.sh.orig	Wed Jul 23 11:20:18 2003
+++ config/ltmain.sh	Mon Aug 18 22:41:00 2003
@@ -1075,12 +1075,17 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
 	  esac
 	fi
+	deplibs="$deplibs $arg"
+	continue
+	;;
+
+      -?thread)
 	deplibs="$deplibs $arg"
 	continue
 	;;
