--- ltmain.sh.orig	Sun Sep 19 08:34:44 2004
+++ ltmain.sh	Mon Mar  7 12:53:53 2005
@@ -1477,7 +1477,7 @@
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
@@ -1494,6 +1494,12 @@
 
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
 
@@ -1977,6 +1983,7 @@
 	    finalize_deplibs="$deplib $finalize_deplibs"
 	  else
 	    deplibs="$deplib $deplibs"
+	    test "$linkmode" = lib && newdependency_libs="$deplib $newdependency_libs"
 	  fi
 	  continue
 	  ;;
@@ -3084,7 +3091,7 @@
 
 	# Check that each of the things are valid numbers.
 	case $current in
-	0 | [1-9] | [1-9][0-9] | [1-9][0-9][0-9]) ;;
+	0|[1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1-9][0-9][0-9][0-9]|[1-9][0-9][0-9][0-9][0-9]) ;;	
 	*)
 	  $echo "$modename: CURRENT \`$current' is not a nonnegative integer" 1>&2
 	  $echo "$modename: \`$vinfo' is not valid version information" 1>&2
@@ -3093,7 +3100,7 @@
 	esac
 
 	case $revision in
-	0 | [1-9] | [1-9][0-9] | [1-9][0-9][0-9]) ;;
+	0|[1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1-9][0-9][0-9][0-9]|[1-9][0-9][0-9][0-9][0-9]) ;;
 	*)
 	  $echo "$modename: REVISION \`$revision' is not a nonnegative integer" 1>&2
 	  $echo "$modename: \`$vinfo' is not valid version information" 1>&2
@@ -3102,7 +3109,7 @@
 	esac
 
 	case $age in
-	0 | [1-9] | [1-9][0-9] | [1-9][0-9][0-9]) ;;
+	0|[1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1-9][0-9][0-9][0-9]|[1-9][0-9][0-9][0-9][0-9]) ;;
 	*)
 	  $echo "$modename: AGE \`$age' is not a nonnegative integer" 1>&2
 	  $echo "$modename: \`$vinfo' is not valid version information" 1>&2
@@ -4442,6 +4449,9 @@
 	  compile_command=`$echo "X$compile_command" | $Xsed -e "s%@SYMFILE@%$output_objdir/${outputname}S.${objext}%"`
 	  finalize_command=`$echo "X$finalize_command" | $Xsed -e "s%@SYMFILE@%$output_objdir/${outputname}S.${objext}%"`
 	  ;;
+	*-*-freebsd*)
+	  # FreeBSD doesn't need this...
+	  ;;
 	*)
 	  $echo "$modename: unknown suffix for \`$dlsyms'" 1>&2
 	  exit $EXIT_FAILURE
@@ -5527,10 +5537,17 @@
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
