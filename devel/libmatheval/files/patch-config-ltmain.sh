--- config/ltmain.sh.orig	2013-03-11 15:30:13.000000000 +0400
+++ config/ltmain.sh	2013-03-11 15:30:15.000000000 +0400
@@ -3025,7 +3025,6 @@
 	func_basename "$file"
 	name="$func_basename_result"
 	instname="$dir/$name"i
-	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
 
 	# Maybe install the static library, too.
 	test -n "$old_library" && func_append staticlibs " $dir/$old_library"
