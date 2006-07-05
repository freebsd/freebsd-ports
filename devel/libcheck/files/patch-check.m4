--- check.m4.orig	Tue Mar  1 01:25:26 2005
+++ check.m4	Sun Jul  2 21:13:20 2006
@@ -19,8 +19,21 @@
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
+
+      for check_libdir in /usr/local/lib /usr/local/lib/check /usr/lib $prefix/lib
+      do
+        if test -e $check_libdir/libcheck.a ; then
+          CHECK_LIBS="-L${check_libdir} -lcheck"
+          break
+        fi
+      done
     fi
 
     ac_save_CFLAGS="$CFLAGS"
