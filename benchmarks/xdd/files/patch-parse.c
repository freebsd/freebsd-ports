--- parse.c.orig	Thu Jun  1 14:48:28 2006
+++ parse.c	Thu Jun  1 14:56:44 2006
@@ -697,7 +697,7 @@
 xddfunc_delay(int32_t argc, char *argv[])
 { 
 	xgp->passdelay = atoi(argv[1]);
-    return(1);
+    return(2);
 }
 /*----------------------------------------------------------------------------*/
 // Delete the target file when complete
@@ -1101,7 +1101,7 @@
 xddfunc_maxerrors(int32_t argc, char *argv[])
 {
 	xgp->max_errors = atoi(argv[1]);
-    return(1);
+    return(2);
 }
 /*----------------------------------------------------------------------------*/
 // Set the maximum runtime priority
