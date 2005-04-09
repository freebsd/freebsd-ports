--- config.m4.bak	Mon Apr  4 20:14:03 2005
+++ config.m4	Mon Apr  4 20:14:20 2005
@@ -39,7 +39,7 @@
   ],[
     AC_MSG_ERROR([wrong libstatgrab version or lib not found, Statgrab version 0.10+ is required.])
   ],[
-    -L$STATGRAB_DIR/lib -lm -ldl
+    -L$STATGRAB_DIR/lib
   ])
   dnl
   PHP_SUBST(STATGRAB_SHARED_LIBADD)
