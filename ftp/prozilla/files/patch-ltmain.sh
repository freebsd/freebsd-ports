--- ltmain.sh.orig	Wed Nov  2 13:02:43 2005
+++ ltmain.sh	Thu Nov 10 16:33:44 2005
@@ -5771,11 +5771,13 @@
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
