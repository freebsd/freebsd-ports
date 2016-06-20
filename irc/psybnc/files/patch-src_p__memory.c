--- src/p_memory.c.orig	2016-06-20 14:41:27 UTC
+++ src/p_memory.c
@@ -32,10 +32,10 @@ FILE *logm=NULL;
 
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
@@ -53,7 +53,7 @@ unsigned long *__pmalloc(unsigned long s
     return rc;
 }
 
-void _pfree(unsigned long *pointer, char *module, char *function, int line)
+void _pfree(char *pointer, char *module, char *function, int line)
 {
 #ifdef LOGALLOC
     if(logm==NULL)
@@ -67,7 +67,7 @@ void _pfree(unsigned long *pointer, char
     free(pointer);
 }
 
-#define free(a) _pfree((void *)a,__FILE__,__FUNCTION__,__LINE__)
+#define free(a) _pfree((void *)a,__FILE__,(char*)__FUNCTION__,__LINE__)
 
 /* struct wrappers. Those alloc, delete and return the needed structures */
 
