
$FreeBSD$

--- libIDL/ltmain.sh.orig	Mon Mar 11 14:42:53 2002
+++ libIDL/ltmain.sh	Tue Mar 12 16:39:28 2002
@@ -1042,6 +1042,9 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
+	  *-*-freebsd*)
+	    # has libc, but it shouldn't be explicitly linked in
+	    ;;
 	  esac
 	fi
 	deplibs="$deplibs $arg"
@@ -2438,6 +2441,9 @@
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
+	  *-*-freebsd*)
+	    # has libc, but it shouldn't be explicitly linked in
+	    ;;
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test $build_libtool_need_lc = "yes"; then
@@ -4223,10 +4229,12 @@
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
