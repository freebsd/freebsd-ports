--- ac-helpers/ltmain.sh.orig	Thu Oct 23 17:15:47 2003
+++ ac-helpers/ltmain.sh	Tue Nov 11 15:04:17 2003
@@ -1072,7 +1072,7 @@
 	  esac
 	 elif test "X$arg" = "X-lc_r"; then
 	  case $host in
-	 *-*-openbsd* | *-*-freebsd*)
+	 *-*-openbsd* | *-*-freebsd4*)
 	    # Do not include libc_r directly, use -pthread flag.
 	    continue
 	    ;;
@@ -1212,7 +1212,12 @@
 	;;
 
       -Kthread | -mthreads | -mt | -pthread | -pthreads | -threads | -qthreaded | -kthread )
-        compiler_flags="$compiler_flags $arg"
+        pthread=yes
+	arg=$arg
+	linker_flags="$linker_flags $arg"
+	compiler_flags="$compiler_flags $arg"
+	compile_command="$compile_command $arg"
+	finalize_command="$finalize_command $arg"
 	continue
 	;;
 
