--- ltmain.sh.orig	Sat Nov 30 21:32:08 2002
+++ ltmain.sh	Tue Dec  3 22:59:51 2002
@@ -1037,8 +1037,16 @@
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
 
@@ -2405,7 +2413,7 @@
 	    # Rhapsody C library is in the System framework
 	    deplibs="$deplibs -framework System"
 	    ;;
-	  *-*-netbsd*)
+	  *-*-netbsd* | *-*-freebsd*)
 	    # Don't link with libc until the a.out ld.so is fixed.
 	    ;;
 	  *)
@@ -4175,10 +4183,12 @@
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
