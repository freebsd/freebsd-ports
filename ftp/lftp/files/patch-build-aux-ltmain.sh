--- build-aux/ltmain.sh.orig
+++ build-aux/ltmain.sh
@@ -4230,12 +4230,6 @@
 	  func_execute_cmds "$postinstall_cmds" 'exit $?'
 	fi
 
-	# Install the pseudo-library for information purposes.
-	func_basename "$file"
-	name=$func_basename_result
-	instname=$dir/${name}i
-	func_show_eval "$install_prog $instname $destdir/$name" 'exit $?'
-
 	# Maybe install the static library, too.
 	test -n "$old_library" && func_append staticlibs " $dir/$old_library"
 	;;
