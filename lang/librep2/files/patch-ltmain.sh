--- ltmain.sh.orig	Wed Jan 23 11:38:40 2002
+++ ltmain.sh	Sun Feb  3 01:44:17 2002
@@ -1037,8 +1037,16 @@
 	continue
 	;;
 
+      -pthread)
+	compile_command="$compile_command -pthread"
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
 
