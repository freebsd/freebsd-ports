--- ltmain.sh.orig	Thu Aug 23 07:47:42 2001
+++ ltmain.sh	Tue Dec 11 22:07:52 2001
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
@@ -4175,10 +4178,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false ; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
