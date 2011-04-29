--- ../gcc/config/i386/i386.c.orig	2011-02-20 21:45:59.000000000 +0000
+++ ../gcc/config/i386/i386.c	2011-02-20 21:47:35.000000000 +0000
@@ -1762,7 +1762,7 @@
 	     "-mtune=generic instead as appropriate.");
 
   if (!ix86_arch_string)
-    ix86_arch_string = TARGET_64BIT ? "x86-64" : "i386";
+    ix86_arch_string = TARGET_64BIT ? "x86-64" : "i486";
   /* APPLE LOCAL begin mainline */
   else
     ix86_arch_specified = 1;
