--- src/oracle_functions.c.orig	Wed Jun  8 19:39:20 2005
+++ src/oracle_functions.c	Wed Jun  8 19:39:32 2005
@@ -48,6 +48,7 @@
 
 long local_min(long a, long b){if(a<b)return a; return b;}
 
+#if 0
 int epc_exit_handler()
 {
   /* in oracle 8.1.6 and 8.1.7 libclntsh.so registers an
@@ -65,6 +66,7 @@
     printf("neener neener caught the exit handler bug!\n");
   return 0;
 }
+#endif
 
 #ifdef UNIX_DEBUG
 /*
