--- ltmain.sh.orig	Mon May 16 02:39:29 2005
+++ ltmain.sh	Thu Jun 16 19:42:32 2005
@@ -1525,2 +1525,3 @@
 	finalize_command="$finalize_command $arg"
+	deplibs="$deplibs $arg"
 	continue
@@ -1530,2 +1531,8 @@
 	module=yes
+	case $host in
+	*-*-freebsd*)
+	  # Do not build the useless static library
+	  build_old_libs=no
+	  ;;
+	esac
 	continue
@@ -2015,2 +2022,25 @@
 	  fi
+
+	  case $linkmode in
+	  lib)
+	    deplibs="$deplib $deplibs"
+	    test "$pass" = conv && continue
+	    newdependency_libs="$deplib $newdependency_libs"
+	    ;;
+	  prog)
+	    if test "$pass" = conv; then
+	      deplibs="$deplib $deplibs"
+	      continue
+	    fi
+	    if test "$pass" = scan; then
+	      deplibs="$deplib $deplibs"
+	    else
+	      compile_deplibs="$deplib $compile_deplibs"
+	      finalize_deplibs="$deplib $finalize_deplibs"
+	    fi
+	    ;;
+	  *)
+	    ;;
+	  esac # linkmode
+
 	  continue
@@ -4498,2 +4528,5 @@
 	  ;;
+	*-*-freebsd*)
+	  # FreeBSD doesn't need this...
+	  ;;
 	*)
@@ -5627,6 +5660,13 @@
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
 
