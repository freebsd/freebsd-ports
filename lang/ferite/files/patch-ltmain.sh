--- ltmain.sh.orig	Tue Aug 14 16:55:55 2001
+++ ltmain.sh	Sun Aug 26 09:11:33 2001
@@ -944,6 +944,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -4175,10 +4176,12 @@
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
