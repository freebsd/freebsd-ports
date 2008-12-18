--- build-aux/ltmain.sh.orig	2008-12-15 18:04:37.000000000 +0100
+++ build-aux/ltmain.sh	2008-12-15 18:07:52.000000000 +0100
@@ -2077,10 +2077,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if false; then
 	func_basename "$file"
 	name="$func_basename_result"
 	instname="$dir/$name"i
 	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
