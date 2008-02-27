diff -urN src/p_memory.c psybnc.new/src/p_memory.c
--- src/p_memory.c	2005-06-04 22:22:45.000000000 +0400
+++ src/p_memory.c	2008-02-25 23:31:29.000000000 +0300
@@ -32,10 +32,10 @@
 
 /* malloc-wrapper. No memory will log an error entry and kill the bouncer */
 
-unsigned long *__pmalloc(unsigned long size,char *module,char *function, int line)
+char *__pmalloc(unsigned long size,char *module,char *function, int line)
 {
-    unsigned long *rc;
-    if (!(rc=(unsigned long *)malloc(size)))
+    char *rc;
+    if (!(rc=(char *)malloc(size)))
     {
 	p_log(LOG_ERROR,-1,lngtxt(602),module,function,line);
 	exit(0x0);
@@ -53,7 +53,7 @@
     return rc;
 }
 
-void _pfree(unsigned long *pointer, char *module, char *function, int line)
+void _pfree(char *pointer, char *module, char *function, int line)
 {
 #ifdef LOGALLOC
     if(logm==NULL)
@@ -67,7 +67,7 @@
     free(pointer);
 }
 
-#define free(a) _pfree((void *)a,__FILE__,__FUNCTION__,__LINE__)
+#define free(a) _pfree((void *)a,__FILE__,(char*)__FUNCTION__,__LINE__)
 
 /* struct wrappers. Those alloc, delete and return the needed structures */
