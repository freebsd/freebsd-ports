
$FreeBSD$

--- ltmain.sh.orig	Mon Jan  7 11:09:55 2002
+++ ltmain.sh	Thu Jan 24 16:32:50 2002
@@ -1795,6 +1795,9 @@
 	*-*-cygwin* | *-*-mingw* | *-*-os2* | *-*-beos*)
 	  # these systems don't actually have a c library (as such)!
 	  ;;
+	*-*-freebsd*)
+	  # has libc, but it shouldn't be explicitly linked in
+	  ;;
         *-*-rhapsody*)
 	  # rhapsody is a little odd...
 	  deplibs="$deplibs -framework System"
@@ -3360,10 +3366,12 @@
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
