--- src/emacs.c.~1~	Tue Aug 18 14:48:38 1998
+++ src/emacs.c	Fri Sep 20 23:04:16 2002
@@ -510,8 +510,6 @@
 {
   char stack_bottom_variable;
   int skip_args = 0;
-  extern int errno;
-  extern sys_nerr;
 
 #ifdef LINUX_SBRK_BUG
   __sbrk (1);
