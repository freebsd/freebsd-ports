--- ltmain.sh.orig	Fri Sep  1 10:46:39 2000
+++ ltmain.sh	Tue Nov 25 06:49:01 2003
@@ -1091,6 +1091,13 @@
 	deplibs="$deplibs $arg"
 	;;
 
+      -pthread)
+        compile_command="$compile_command -pthread"
+        finalize_command="$finalize_command -pthread"
+        compiler_flags="$compiler_flags -pthread"
+        continue
+        ;;
+
       -module)
 	module=yes
 	continue
@@ -1926,7 +1933,7 @@
 	  set dummy $deplibs_check_method
 	  file_magic_regex="`expr \"$deplibs_check_method\" : \"$2 \(.*\)\"`"
 	  for a_deplib in $deplibs; do
-	    name="`expr $a_deplib : '-l\(.*\)'`"
+	    name="`expr \( $a_deplib : '-l\(.*\)' \)`"
 	    # If $name is empty we are operating on a -L argument.
 	    if test "$name" != "" ; then
 	      libname=`eval \\$echo \"$libname_spec\"`
