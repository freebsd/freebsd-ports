--- hanzim.c.orig	Sat Apr 14 21:23:42 2001
+++ hanzim.c	Sat Apr 14 21:29:54 2001
@@ -440,10 +440,14 @@
   struct _timeb tp;
   _ftime(&tp);
 #else
+/*
   struct timeb	tp;
   ftime(&tp);
+*/
+  time_t	t;
+  time(&t);
 #endif
-  srand(tp.millitm);
+  srand(t);
 
   printf("\n\nWelcome to Hanzi Master, where YOU will master the hanzi.\n\n");
   printf("Please use \"Ctrl-h\" or \"Alt-h\" for help.\n");
