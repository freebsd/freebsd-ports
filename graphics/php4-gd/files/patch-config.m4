--- config.m4.orig	Thu Dec 25 23:33:02 2003
+++ config.m4	Wed Jul  7 14:37:18 2004
@@ -219,7 +219,7 @@
     ],[
       AC_MSG_ERROR([Problem with libt1.(a|so). Please check config.log for more information.]) 
     ],[
-      -L$GD_T1_DIR/lib
+      -L$GD_T1_DIR/lib -lm
     ])
   fi
 ])
