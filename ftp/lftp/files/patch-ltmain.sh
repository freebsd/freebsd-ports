--- build-aux/ltmain.sh.orig	2007-12-29 12:41:13.000000000 +0100
+++ build-aux/ltmain.sh	2008-05-28 16:41:23.818197162 +0200
@@ -6058,10 +6058,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
