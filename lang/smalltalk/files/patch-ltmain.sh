--- config/ltmain.sh.orig	Fri Jun 14 06:37:06 2002
+++ config/ltmain.sh	Thu Jun 27 01:04:35 2002
@@ -961,6 +961,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -2424,6 +2425,9 @@
 	    ;;
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
+	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
 	    ;;
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
