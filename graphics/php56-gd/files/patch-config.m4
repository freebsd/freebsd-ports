--- config.m4.orig	2016-09-15 23:02:50.000000000 +0200
+++ config.m4	2016-09-28 10:10:26.335642000 +0200
@@ -228,7 +228,7 @@ AC_DEFUN([PHP_GD_T1LIB],[
     ],[
       AC_MSG_ERROR([Problem with libt1.(a|so). Please check config.log for more information.])
     ],[
-      -L$GD_T1_DIR/$PHP_LIBDIR
+      -L$GD_T1_DIR/$PHP_LIBDIR -lm
     ])
   fi
 ])
