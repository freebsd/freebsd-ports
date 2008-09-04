--- ltmain.sh.orig	2008-07-26 17:06:14.000000000 +0900
+++ ltmain.sh	2008-07-26 17:06:24.000000000 +0900
@@ -1710,6 +1710,38 @@
 	lib=
 	found=no
 	case $deplib in
+        -mt|-mthreads|-kthread|-Kthread|-pthread|-pthreads|--thread-safe|-threads)
+          if test "$linkmode,$pass" = "prog,link"; then
+            compile_deplibs="$deplib $compile_deplibs"
+            finalize_deplibs="$deplib $finalize_deplibs"
+          else
+            compiler_flags="$compiler_flags $deplib"
+          fi
+
+          case $linkmode in
+          lib)
+            deplibs="$deplib $deplibs"
+            test "$pass" = conv && continue
+            newdependency_libs="$deplib $newdependency_libs"
+            ;;
+          prog)
+            if test "$pass" = conv; then
+              deplibs="$deplib $deplibs"
+              continue
+            fi
+            if test "$pass" = scan; then
+              deplibs="$deplib $deplibs"
+            else
+              compile_deplibs="$deplib $compile_deplibs"
+              finalize_deplibs="$deplib $finalize_deplibs"
+            fi
+            ;;
+          *)
+            ;;
+          esac # linkmode
+
+          continue
+          ;;
 	-l*)
 	  if test $linkmode != lib && test $linkmode != prog; then
 	    $echo "$modename: warning: \`-l' is ignored for archives/objects" 1>&2
