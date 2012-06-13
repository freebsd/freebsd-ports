--- config/ltmain.sh.orig	2010-11-19 01:46:29.000000000 -0800
+++ config/ltmain.sh	2010-11-19 01:46:38.000000000 -0800
@@ -2076,14 +2076,6 @@
 	  func_execute_cmds "$postinstall_cmds" 'exit $?'
 	fi
 
-	# Install the pseudo-library for information purposes.
-	func_basename "$file"
-	name="$func_basename_result"
-	instname="$dir/$name"i
-	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
-
-	# Maybe install the static library, too.
-	test -n "$old_library" && staticlibs="$staticlibs $dir/$old_library"
 	;;
 
       *.lo)
