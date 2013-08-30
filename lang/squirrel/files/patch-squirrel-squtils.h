--- squirrel/squtils.h.orig	2008-10-14 18:36:01.000000000 +0400
+++ squirrel/squtils.h	2013-08-30 19:26:36.769227465 +0400
@@ -2,6 +2,11 @@
 #ifndef _SQUTILS_H_
 #define _SQUTILS_H_
 
+/* clang fix: "error: call to function 'sq_vm_free' that is neither visible in the template definition nor found by argument-dependent lookup" */
+void *sq_vm_malloc(SQUnsignedInteger size);
+void *sq_vm_realloc(void *p,SQUnsignedInteger oldsize,SQUnsignedInteger size);
+void sq_vm_free(void *p,SQUnsignedInteger size);
+
 #define sq_new(__ptr,__type) {__ptr=(__type *)sq_vm_malloc(sizeof(__type));new (__ptr) __type;}
 #define sq_delete(__ptr,__type) {__ptr->~__type();sq_vm_free(__ptr,sizeof(__type));}
 #define SQ_MALLOC(__size) sq_vm_malloc((__size));
