--- gcc/config/i386/i386.c.orig	2020-08-28 09:37:26.849947000 -0700
+++ gcc/config/i386/i386.c	2020-08-28 09:37:51.260814000 -0700
@@ -8747,7 +8747,7 @@ function_arg_advance_32 (CUMULATIVE_ARGS *cum, machine
 			 HOST_WIDE_INT words)
 {
   int res = 0;
-  bool error_p = NULL;
+  bool error_p = false;
 
   if (TARGET_IAMCU)
     {
