--- ltmain.sh.orig	2010-08-20 10:37:34.875162866 +0200
+++ ltmain.sh	2010-08-20 10:38:15.964421976 +0200
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
