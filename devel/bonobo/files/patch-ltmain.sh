--- ltmain.sh.orig	Sun Oct  6 15:24:35 2002
+++ ltmain.sh	Fri Oct 11 02:13:11 2002
@@ -1249,8 +1249,17 @@
 	continue
 	;;
 
+      -pthread)
+      compile_command="$compile_command -pthread"
+      finalize_command="$finalize_command -pthread"
+      compiler_flags="$compiler_flags -pthread"
+      continue
+      ;;
+
+
       -module)
 	module=yes
+        build_old_libs=no
 	continue
 	;;
 
@@ -2841,6 +2850,9 @@
 	    # Do not include libc due to us having libc/libc_r.
 	    test "X$arg" = "X-lc" && continue
 	    ;;
+          *-*-freebsd*)
+            # FreeBSD doesn't need this...
+            ;;
  	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test "$build_libtool_need_lc" = "yes"; then
@@ -4715,10 +4727,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+        if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+        fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
