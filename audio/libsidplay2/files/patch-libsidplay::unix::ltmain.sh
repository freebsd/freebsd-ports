--- libsidplay/unix/ltmain.sh.orig	Tue Dec 24 05:38:47 2002
+++ libsidplay/unix/ltmain.sh	Wed Jan 22 04:51:36 2003
@@ -1221,7 +1221,7 @@
 	    # These systems don't actually have a C library (as such)
 	    test "X$arg" = "X-lc" && continue
 	    ;;
-	  *-*-openbsd*)
+	  *-*-openbsd* | *-*-freebsd*)
 	    # OpenBSD uses either libc or libc_r.
 	    continue
 	    ;;
@@ -1233,7 +1233,7 @@
 	fi
         if test "X$arg" = "X-lc_r"; then
          case $host in
-         *-*-openbsd*)
+         *-*-openbsd* | *-*-freebsd*)
            # Do not include libc_r directly, use -pthread flag.
            continue
            ;;
@@ -2814,7 +2814,7 @@
 	  *-*-netbsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
-          *-*-openbsd*)
+          *-*-openbsd* | *-*-freebsd*)
 	    # OpenBSD uses either libc or libc_r.
             ;;
  	  *)
@@ -4672,10 +4672,12 @@
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
