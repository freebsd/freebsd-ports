--- ltmain.sh.orig	Sat Mar  2 01:46:01 2002
+++ ltmain.sh	Sat Mar  2 01:48:30 2002
@@ -958,6 +958,7 @@
 	;;
 
       -avoid-version)
+	build_old_libs=no
 	avoid_version=yes
 	continue
 	;;
@@ -4247,11 +4248,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
-
+	fi
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
 	;;
