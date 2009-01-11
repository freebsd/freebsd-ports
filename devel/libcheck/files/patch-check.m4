--- check.m4.orig	2008-12-29 21:48:46.000000000 +0800
+++ check.m4	2009-01-07 09:02:41.452952376 +0800
@@ -21,8 +21,20 @@
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
