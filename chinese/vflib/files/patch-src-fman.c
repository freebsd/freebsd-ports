--- src/fman.c.orig	Fri Jan 19 03:42:46 2007
+++ src/fman.c	Fri Jan 19 03:44:56 2007
@@ -392,13 +392,13 @@
 Private CACHE  *RequireCache();
 Private int    LRUMoveTop();
 Private int    LRUPutTop();
+Private int    LRUPutTop2();
 Private int    LRUDeleteTail();
+Private void   ReturnCache();
 Private CACHE  *HashIsInterned();
 Private int    HashInternIt();
 Private int    HashUninternIt();
 
-
-
 /* 
  * InitCache()  - Init cache.  Must specify cache size and hash table size.
  *    Returns FALSE if out of memory or other fatal error.
@@ -480,7 +480,6 @@
      int port;
 {
   CACHE         *cptr;
-  Private void  ReturnCache();
 
   if ((cptr = RequireCache()) == (CACHE*)NULL){
     fprintf(stderr, "VFlib: CacheIt() - error\n");
@@ -542,7 +541,6 @@
   CACHE  *cptr;
 {
   CACHE       *cptr_b, *cptr_f;
-  Private int LRUPutTop2();
 
   cptr_b         = cptr->l_back;
   cptr_f         = cptr->l_forw;
@@ -558,8 +556,6 @@
 LRUPutTop(cptr)
   CACHE  *cptr;
 {
-  Private int LRUPutTop2();
-
   return LRUPutTop2(cptr, TRUE);
 }
   
