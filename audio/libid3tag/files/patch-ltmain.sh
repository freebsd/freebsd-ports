--- ltmain.sh.orig	Tue Feb 17 02:52:36 2004
+++ ltmain.sh	Fri Oct 28 09:34:46 2005
@@ -2980,8 +2980,8 @@
 	  ;;
 
 	freebsd-elf)
-	  major=".$current"
-	  versuffix=".$current";
+	  major=.`expr $current - $age`
+	  versuffix="$major";
 	  ;;
 
 	irix | nonstopux)
@@ -5527,11 +5527,6 @@
 	  IFS="$save_ifs"
 	fi
 
-	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
