--- config.m4.orig	Mon May 30 01:16:41 2005
+++ config.m4	Wed Dec  7 11:01:13 2005
@@ -220,7 +220,7 @@
     ],[
       AC_MSG_ERROR([Problem with libt1.(a|so). Please check config.log for more information.]) 
     ],[
-      -L$GD_T1_DIR/$PHP_LIBDIR
+      -L$GD_T1_DIR/$PHP_LIBDIR -lm
     ])
   fi
 ])
