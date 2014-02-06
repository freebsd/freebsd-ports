--- ltmain.sh.orig	2004-02-16 20:52:36.000000000 -0500
+++ ltmain.sh
@@ -1335,7 +1335,7 @@ EOF
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd* | *-*-freebsd*)
+	  *-*-openbsd* | *-*-freebsd* | *-*-dragonfly* )
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
@@ -1346,7 +1346,7 @@ EOF
 	  esac
 	elif test "X$arg" = "X-lc_r"; then
 	 case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd* | *-*-dragonfly* )
 	   # Do not include libc_r directly, use -pthread flag.
 	   continue
 	   ;;
@@ -2980,8 +2980,8 @@ EOF
 	  ;;
 
 	freebsd-elf)
-	  major=".$current"
-	  versuffix=".$current";
+	  major=.`expr $current - $age`
+	  versuffix="$major";
 	  ;;
 
 	irix | nonstopux)
@@ -5527,11 +5527,6 @@ relink_command=\"$relink_command\""
 	  IFS="$save_ifs"
 	fi
 
-	# Install the pseudo-library for information purposes.
-	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
-	instname="$dir/$name"i
-	$show "$install_prog $instname $destdir/$name"
-	$run eval "$install_prog $instname $destdir/$name" || exit $?
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
