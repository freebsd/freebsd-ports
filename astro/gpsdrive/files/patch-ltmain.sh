$FreeBSD$

--- ltmain.sh.orig	Wed Sep 26 23:26:27 2001
+++ ltmain.sh	Sat Nov 17 08:35:28 2001
@@ -1043,7 +1043,7 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
@@ -2441,7 +2441,7 @@
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    ;;
 	  *)
@@ -4210,10 +4210,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false ; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
