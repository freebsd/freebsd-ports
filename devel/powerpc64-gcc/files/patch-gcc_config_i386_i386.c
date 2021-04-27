--- gcc/config/i386/i386.c.orig	2017-05-05 21:51:14 UTC
+++ gcc/config/i386/i386.c
@@ -8686,7 +8686,7 @@ function_arg_advance_32 (CUMULATIVE_ARGS *cum, machine
 			 HOST_WIDE_INT words)
 {
   int res = 0;
-  bool error_p = NULL;
+  bool error_p = 0;
 
   if (TARGET_IAMCU)
     {
