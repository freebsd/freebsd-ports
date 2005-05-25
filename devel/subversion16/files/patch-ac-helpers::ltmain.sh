--- ac-helpers/ltmain.sh.orig	Fri May 20 21:41:54 2005
+++ ac-helpers/ltmain.sh	Wed May 25 14:38:21 2005
@@ -1492,7 +1492,7 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd* | *-*-freebsd* | *-*-dragonfly*)
+	  *-*-openbsd* | *-*-freebsd4* | *-*-dragonfly*)
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
