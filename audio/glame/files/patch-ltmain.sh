
$FreeBSD$

--- ltmain.sh.orig	Mon Dec 10 12:53:39 2001
+++ ltmain.sh	Thu Dec 20 17:29:14 2001
@@ -1052,7 +1052,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd[234]*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
@@ -2359,6 +2359,9 @@
 	    # problems, so we reset it completely
 	    verstring=""
 	    ;;
+	  *-*-freebsd*)
+	    # FreeBSD doesn't need this...
+	    ;;
 	  *)
 	    verstring="0.0"
 	    ;;
@@ -4247,10 +4250,12 @@
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
