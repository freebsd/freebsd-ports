--- parse.c.orig	Fri Mar 16 07:10:44 2007
+++ parse.c	Fri Mar 16 07:11:44 2007
@@ -810,7 +810,7 @@
 xddfunc_delay(int32_t argc, char *argv[])
 { 
 	xgp->passdelay = atoi(argv[1]);
-    return(1);
+    return(2);
 }
 /*----------------------------------------------------------------------------*/
 // Delete the target file when complete
@@ -1218,7 +1218,7 @@
 xddfunc_maxerrors(int32_t argc, char *argv[])
 {
 	xgp->max_errors = atoll(argv[1]);
-    return(1);
+    return(2);
 }
 /*----------------------------------------------------------------------------*/
 // Set the maximum runtime priority
