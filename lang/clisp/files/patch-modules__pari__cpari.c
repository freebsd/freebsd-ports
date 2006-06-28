--- ./modules/pari/cpari.c.orig	Fri Aug 26 14:57:48 2005
+++ ./modules/pari/cpari.c	Mon Jun 26 18:07:48 2006
@@ -62,9 +62,6 @@
   char *p;
   GEN p1;
 
-  extern ulong init_opts;
-  init_opts = 0;
-
   pari_init(parisize,maxprime);
   /*init_graph();*/
 
@@ -75,6 +72,5 @@
 void fini_for_clisp (int leaving)
 {
   /*free_graph();*/
-  freeall();
   killallfiles(leaving);
 }
