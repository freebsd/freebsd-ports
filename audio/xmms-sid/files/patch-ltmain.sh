--- ltmain.sh.bak	2012-11-20 07:44:50.000000000 -0600
+++ ltmain.sh	2012-11-20 07:45:18.000000000 -0600
@@ -3020,13 +3020,13 @@
 	  lib="$destdir/$realname"
 	  func_execute_cmds "$postinstall_cmds" 'exit $?'
 	fi
-
+	if /usr/bin/false; then
 	# Install the pseudo-library for information purposes.
 	func_basename "$file"
 	name="$func_basename_result"
 	instname="$dir/$name"i
 	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
-
+	fi
 	# Maybe install the static library, too.
 	test -n "$old_library" && func_append staticlibs " $dir/$old_library"
 	;;
