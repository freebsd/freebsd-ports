--- source/modules.c.orig	Tue Feb 18 14:58:09 2003
+++ source/modules.c	Tue Feb 18 14:58:23 2003
@@ -65,7 +65,7 @@
 
 Function_ptr global_table[NUMBER_OF_GLOBAL_FUNCTIONS] = { NULL };
 extern int read_sockets();
-extern unsigned long bitchx_numver;
+extern const unsigned long bitchx_numver;
 extern int identd;
 
 extern int (*dcc_open_func) (int, int, unsigned long, int);
