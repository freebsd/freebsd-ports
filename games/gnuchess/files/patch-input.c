--- src/input.c.orig	Tue Jun  5 23:34:06 2007
+++ src/input.c	Tue Jun  5 23:34:14 2007
@@ -92,7 +92,7 @@
   fgets(inputstr, MAXSTR, stdin);
 }
 
-static pthread_t input_thread;
+pthread_t input_thread;
 
 /* Mutex and condition variable for thread communication */
 
