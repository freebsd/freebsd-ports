--- src/squirrel/sqstate.h.orig	2008-12-22 23:38:10.000000000 +0000
+++ src/squirrel/sqstate.h
@@ -113,7 +113,4 @@ extern SQObjectPtr _minusone_;
 
 bool CompileTypemask(SQIntVec &res,const SQChar *typemask);
 
-void *sq_vm_malloc(SQUnsignedInteger size);
-void *sq_vm_realloc(void *p,SQUnsignedInteger oldsize,SQUnsignedInteger size);
-void sq_vm_free(void *p,SQUnsignedInteger size);
 #endif //_SQSTATE_H_
