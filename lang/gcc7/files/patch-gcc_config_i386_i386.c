This fixes

/wrkdirs/usr/ports/lang/gcc7/work/gcc-7.5.0/gcc/config/i386/i386.c:9631:8: error: cannot initialize a variable of type 'bool' with an rvalue of type 'nullptr_t'
  bool error_p = NULL;
       ^         ~~~~

and comes from upstream as part of

  commit 9f36390d429502f0a0dee20bda5b4870da948f6a
  Author: Uros Bizjak <ubizjak@gmail.com>
  Date:   Sat May 6 09:01:51 2017 +0200

  i386.c (ext_80387_constant_init): Do not explicitly initialize to zero.
   
	* config/i386/i386.c (ext_80387_constant_init): Do not explicitly
	initialize to zero.
	(init_regs): Remove declaration.
        (function_arg_advance_32): Initialize error_p as boolean variable.

--- UTC
--- gcc/config/i386/i386.c.orig	2019-11-01 20:30:26 UTC
+++ gcc/config/i386/i386.c
@@ -9628,7 +9628,7 @@ function_arg_advance_32 (CUMULATIVE_ARGS *cum, machine
 			 HOST_WIDE_INT words)
 {
   int res = 0;
-  bool error_p = NULL;
+  bool error_p = false;
 
   if (TARGET_IAMCU)
     {
