--- ltmain.sh.orig	Thu Dec 13 19:09:47 2001
+++ ltmain.sh	Wed Jan 23 01:14:10 2002
@@ -2412,6 +2412,9 @@
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test "$build_libtool_need_lc" = "yes"; then
@@ -4179,10 +4182,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	 if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	 fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
