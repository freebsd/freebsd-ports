--- ltmain.sh.orig	Sun Mar  3 07:38:00 2002
+++ ltmain.sh	Fri Mar  8 01:58:58 2002
@@ -2408,6 +2408,9 @@
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test "$build_libtool_need_lc" = "yes"; then
