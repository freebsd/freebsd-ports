--- ltmain.sh.orig	Tue Apr 13 09:05:11 2004
+++ ltmain.sh	Thu Apr 29 22:49:03 2004
@@ -2980,8 +2980,8 @@
 	  ;;
 
 	freebsd-elf)
-	  major=".$current"
-	  versuffix=".$current";
+	  major=".1"
+	  versuffix=".1";
 	  ;;
 
 	irix | nonstopux)
@@ -5528,10 +5528,12 @@
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
