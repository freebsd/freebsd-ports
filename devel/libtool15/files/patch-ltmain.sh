--- ltmain.sh.orig	Sun Apr 11 05:44:45 2004
+++ ltmain.sh	Wed Jun  9 18:21:15 2004
@@ -1358,3 +1358,3 @@
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
@@ -1375,2 +1375,8 @@
 	module=yes
+	case $host in
+	*-*-freebsd*)
+	  # Do not build the useless static library
+	  build_old_libs=no
+	  ;;
+	esac
 	continue
@@ -1858,2 +1864,3 @@
 	    deplibs="$deplib $deplibs"
+	    test "$linkmode" = lib && newdependency_libs="$deplib $newdependency_libs"
 	  fi
@@ -4409,2 +4416,5 @@
 	  ;;
+	*-*-freebsd*)
+	  # FreeBSD doesn't need this...
+	  ;;
 	*)
@@ -5549,6 +5559,13 @@
 	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	case $host in
+	*-*-freebsd*)
+	  # Do not install the useless pseudo-library
+	  ;;
+	*)
+	  name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
+	  instname="$dir/$name"i
+	  $show "$install_prog $instname $destdir/$name"
+	  $run eval "$install_prog $instname $destdir/$name" || exit $?
+	  ;;
+	esac
 
