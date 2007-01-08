--- ltmain.sh.orig	Thu Jan  4 15:07:04 2007
+++ ltmain.sh	Thu Jan  4 15:07:48 2007
@@ -1413,6 +1413,9 @@
 	esac
       fi
       for deplib in $libs; do
+        if test "$deplib" = "-pthread"; then
+	  continue
+	fi
 	lib=
 	found=no
 	case $deplib in
