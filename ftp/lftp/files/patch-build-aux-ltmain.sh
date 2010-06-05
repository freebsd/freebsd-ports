--- build-aux/ltmain.sh.orig	2010-05-20 17:09:31.539282017 +0000
+++ build-aux/ltmain.sh	2010-05-20 17:10:11.971297050 +0000
@@ -2076,12 +2076,6 @@
 	  func_execute_cmds "$postinstall_cmds" 'exit $?'
 	fi
 
-	# Install the pseudo-library for information purposes.
-	func_basename "$file"
-	name="$func_basename_result"
-	instname="$dir/$name"i
-	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
-
 	# Maybe install the static library, too.
 	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
 	;;
