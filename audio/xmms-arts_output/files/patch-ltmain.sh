--- ltmain.sh.orig	Wed Aug  6 19:13:39 2003
+++ ltmain.sh	Tue Nov 11 22:47:49 2003
@@ -1075,7 +1075,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
@@ -1084,6 +1084,13 @@
 	deplibs="$deplibs $arg"
 	continue
 	;;
+
+      -pthread)
+        compile_command="$compile_command -pthread"
+        finalize_command="$finalize_command -pthread"
+        compiler_flags="$compiler_flags -pthread"
+        continue
+        ;;
 
       -module)
 	module=yes
