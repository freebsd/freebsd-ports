--- ltmain.sh.orig	Fri Apr 12 08:48:14 2002
+++ ltmain.sh	Fri Apr 25 16:34:45 2003
@@ -4224,11 +4224,13 @@
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
