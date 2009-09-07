--- config/ltmain.sh.orig	2009-09-08 01:06:40.961772193 +0800
+++ config/ltmain.sh	2009-09-08 01:06:54.440767557 +0800
@@ -2077,10 +2077,12 @@
 	fi
 
 	# Install the pseudo-library for information purposes.
+	if /usr/bin/false ; then
 	func_basename "$file"
 	name="$func_basename_result"
 	instname="$dir/$name"i
 	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
+	fi
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
