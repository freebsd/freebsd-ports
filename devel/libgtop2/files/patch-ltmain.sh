--- ltmain.sh.orig	Tue Jan 14 00:02:45 2003
+++ ltmain.sh	Tue Jan 14 00:05:36 2003
@@ -1073,8 +1073,16 @@
 	continue
 	;;
 
+      -pthread)
+        compile_command="$compile_command -pthread"
+	finalize_command="$finalize_command -pthread"
+	compiler_flags="$compiler_flags -pthread"
+	continue
+	;;
+
       -module)
 	module=yes
+	build_old_libs=no
 	continue
 	;;
 
@@ -2502,6 +2510,9 @@
 	  *-*-openbsd*)
 	    # Do not include libc due to us having libc/libc_r.
 	    ;;
+	  *-*-freebsd*)
+	    # FReeBSD doesn't need this...
+	    ;;
 	  *)
 	    # Add libc to deplibs on all other systems if necessary.
 	    if test "$build_libtool_need_lc" = "yes"; then
@@ -4286,10 +4297,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false; then
 	name=`$echo "X$file" | $Xsed -e 's%^.*/%%'`
 	instname="$dir/$name"i
 	$show "$install_prog $instname $destdir/$name"
 	$run eval "$install_prog $instname $destdir/$name" || exit $?
+        fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
