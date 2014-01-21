--- config.m4.orig	2013-12-11 00:31:06.000000000 +0100
+++ config.m4	2013-12-24 21:11:19.000000000 +0100
@@ -233,7 +233,7 @@
     ],[
       AC_MSG_ERROR([Problem with libt1.(a|so). Please check config.log for more information.])
     ],[
-      -L$GD_T1_DIR/$PHP_LIBDIR
+      -L$GD_T1_DIR/$PHP_LIBDIR -lm
     ])
   fi
 ])
