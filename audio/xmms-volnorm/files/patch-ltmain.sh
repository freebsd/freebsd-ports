--- ltmain.sh.orig	Fri Aug 17 13:42:17 2001
+++ ltmain.sh	Fri Aug 17 13:42:52 2001
@@ -4672,11 +4672,13 @@
 	  IFS="$save_ifs"
 	fi
 
+	if false; then
 	# Install the pseudo-library for information purposes.
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
