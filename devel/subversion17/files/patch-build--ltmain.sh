--- build/ltmain.sh.orig	2011-08-26 19:01:42.000000000 +0400
+++ build/ltmain.sh	2011-09-08 00:11:05.000000000 +0400
@@ -5597,7 +5597,7 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd* | *-*-freebsd* | *-*-dragonfly*)
+	  *-*-openbsd* | *-*-freebsd4* | *-*-dragonfly*)
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
