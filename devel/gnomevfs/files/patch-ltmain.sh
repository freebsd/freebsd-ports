
$FreeBSD$

--- ltmain.sh.orig	Sun Jan 20 16:11:07 2002
+++ ltmain.sh	Tue Jan 22 13:34:20 2002
@@ -1060,6 +1060,7 @@
 
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
@@ -2442,6 +2443,9 @@
 	  *-*-openbsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test $build_libtool_need_lc = "yes"; then
@@ -4208,10 +4212,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
