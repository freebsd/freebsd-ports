--- ltmain.sh.orig	Thu May 22 15:25:54 2003
+++ ltmain.sh	Thu Jun 26 01:26:04 2003
@@ -4286,12 +4286,6 @@
 	  IFS="$save_ifs"
 	fi
 
-	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
-
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
 	;;
