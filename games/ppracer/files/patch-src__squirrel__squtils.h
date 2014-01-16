--- ./src/squirrel/squtils.h.orig	2014-01-16 15:30:36.000000000 +0100
+++ ./src/squirrel/squtils.h	2014-01-16 15:30:36.000000000 +0100
@@ -2,6 +2,10 @@
 #ifndef _SQUTILS_H_
 #define _SQUTILS_H_
 
+void *sq_vm_malloc(SQUnsignedInteger size);
+void *sq_vm_realloc(void *p,SQUnsignedInteger oldsize,SQUnsignedInteger size);
+void sq_vm_free(void *p,SQUnsignedInteger size);
+
 #define sq_new(__ptr,__type) {__ptr=(__type *)sq_vm_malloc(sizeof(__type));new (__ptr) __type;}
 #define sq_delete(__ptr,__type) {__ptr->~__type();sq_vm_free(__ptr,sizeof(__type));}
 #define SQ_MALLOC(__size) sq_vm_malloc(__size);
