--- ltmain.sh.orig	Sat Nov 17 07:22:26 2001
+++ ltmain.sh	Wed Feb 20 16:21:57 2002
@@ -2690,6 +2690,9 @@
 	    # Absolute path.
 	    rpath="$rpath$dir:"
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    # Relative path: add a thisdir entry.
 	    rpath="$rpath\$thisdir/$dir:"
@@ -3360,10 +3363,12 @@
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
