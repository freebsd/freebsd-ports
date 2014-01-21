--- config.m4.orig	2013-12-10 20:32:43.000000000 +0100
+++ config.m4	2013-12-24 21:02:03.000000000 +0100
@@ -241,7 +241,7 @@
     ],[
       AC_MSG_ERROR([Problem with libt1.(a|so). Please check config.log for more information.])
     ],[
-      -L$GD_T1_DIR/$PHP_LIBDIR
+      -L$GD_T1_DIR/$PHP_LIBDIR -lm
     ])
   fi
 ])
