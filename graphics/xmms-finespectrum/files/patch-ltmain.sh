--- ltmain.sh.orig	Tue Aug 27 21:59:27 2002
+++ ltmain.sh	Tue Aug 27 22:00:39 2002
@@ -3347,11 +3347,13 @@
 	  IFS="$save_ifs"
 	fi
 
+	if /usr/bin/false; then
 	# Install the pseudo-library for information purposes.
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
