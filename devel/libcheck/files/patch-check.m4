--- check.m4.orig	2015-08-02 19:31:25 UTC
+++ check.m4
@@ -21,8 +21,20 @@ AC_DEFUN([AM_PATH_CHECK],
       CHECK_CFLAGS="-I$with_check/include"
       CHECK_LIBS="-L$with_check/lib -lcheck"
     else
-      CHECK_CFLAGS=""
-      CHECK_LIBS="-lcheck"
+      for check_includedir in /usr/local/include /usr/local/include/check /usr/include $prefix/include
+      do
+        if test -e $check_includedir/check.h ; then
+          CHECK_CFLAGS="-I${check_includedir}"
+          break
+        fi
+      done
+      for check_libdir in /usr/local/lib /usr/local/lib/check /usr/lib $prefix/lib
+      do
+        if test -e $check_libdir/libcheck.a ; then
+          CHECK_LIBS="-L${check_libdir} -lcheck"
+          break
+        fi
+      done
     fi
 
     ac_save_CFLAGS="$CFLAGS"
