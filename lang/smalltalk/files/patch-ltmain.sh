--- ltmain.sh.orig	Thu Apr 26 19:21:26 2001
+++ ltmain.sh	Fri Nov  2 02:58:37 2001
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
