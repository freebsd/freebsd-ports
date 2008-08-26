--- config/ltmain.sh.orig	2008-08-26 16:13:33.000000000 +0400
+++ config/ltmain.sh	2008-08-26 16:14:40.000000000 +0400
@@ -6002,14 +6002,6 @@
 	  IFS="$save_ifs"
 	fi
 
-	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
-
-	# Maybe install the static library, too.
-	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
 	;;
 
       *.lo)
