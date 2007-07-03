--- src/oracle_functions.c.orig	Tue Jul  3 23:11:11 2007
+++ src/oracle_functions.c	Tue Jul  3 23:11:24 2007
@@ -50,6 +50,7 @@
 
 long local_min(long a, long b){if(a<b)return a; return b;}
 
+#if 0
 int epc_exit_handler()
 {
   /* in oracle 8.1.6 and 8.1.7 libclntsh.so registers an
@@ -67,6 +68,7 @@
     printf("neener neener caught the exit handler bug!\n");
   return 0;
 }
+#endif
 
 #ifdef UNIX_DEBUG
 /*
