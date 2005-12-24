--- ltmain.sh.orig	Sun Dec 18 17:14:54 2005
+++ ltmain.sh	Sat Dec 24 12:22:07 2005
@@ -1604,11 +1604,18 @@
 	compiler_flags="$compiler_flags $arg"
 	compile_command="$compile_command $arg"
 	finalize_command="$finalize_command $arg"
+	deplibs="$deplibs $arg"
 	continue
 	;;
 
       -module)
 	module=yes
+	case $host in
+	*-*-freebsd*)
+	  # Do not build the useless static library
+	  build_old_libs=no
+	  ;;
+	esac
 	continue
 	;;
 
@@ -2101,6 +2108,29 @@
 	  else
 	    compiler_flags="$compiler_flags $deplib"
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
 	  ;;
 	-l*)
@@ -4705,6 +4735,9 @@
             ;;
           esac
 	  ;;
+	*-*-freebsd*)
+	  # FreeBSD doesn't need this...
+	  ;;
 	*)
 	  $echo "$modename: unknown suffix for \`$dlsyms'" 1>&2
 	  exit $EXIT_FAILURE
@@ -5995,10 +6028,17 @@
 	fi
 
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
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
