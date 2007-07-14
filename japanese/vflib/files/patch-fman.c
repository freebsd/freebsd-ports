--- src/fman.c.orig	Mon May 10 17:05:20 1999
+++ src/fman.c	Mon Jun  4 16:08:50 2007
@@ -471,6 +471,14 @@
 }
 
 
+Private void
+ReturnCache(cptr)
+  CACHE  *cptr;
+{
+  CDR_FREE_LIST(cptr) = FREE_LIST();
+  FREE_LIST() = cptr;
+}
+
 /*
  * CacheIt() --- cache it.  The cache slot is moved into
  *   the head of the LRU list.
@@ -480,7 +488,6 @@
      int port;
 {
   CACHE         *cptr;
-  Private void  ReturnCache();
 
   if ((cptr = RequireCache()) == (CACHE*)NULL){
     fprintf(stderr, "VFlib: CacheIt() - error\n");
@@ -521,19 +528,36 @@
   return cptr;
 }
 
-Private void
-ReturnCache(cptr)
-  CACHE  *cptr;
-{
-  CDR_FREE_LIST(cptr) = FREE_LIST();
-  FREE_LIST() = cptr;
-}
-
 
 /**
  ** LRU LIST  
  **/
 
+Private int
+LRUPutTop2(cptr, f)
+     CACHE  *cptr;
+     int    f;
+{
+  CACHE       *cptr_f;
+  FILE_Port   port;
+  int         val;
+
+  cptr_f              = CacheLRUList.l_forw;
+  cptr->l_forw        = cptr_f;
+  cptr_f->l_back      = cptr;
+  cptr->l_back        = &CacheLRUList;
+  CacheLRUList.l_forw = cptr;
+
+  val = 0;
+  if (f == TRUE){
+    port = cptr->port;
+    if (VFFM_Internal_Open(port) < 0)
+      val = -1;
+  }
+
+  return val; 
+}
+
 /* LRUMoveTop()  - moves a cache block into the top of LRU list.
  *   THE CACHE *MUST* BE IN LRU LIST.
  */
@@ -542,7 +566,6 @@
   CACHE  *cptr;
 {
   CACHE       *cptr_b, *cptr_f;
-  Private int LRUPutTop2();
 
   cptr_b         = cptr->l_back;
   cptr_f         = cptr->l_forw;
@@ -558,36 +581,9 @@
 LRUPutTop(cptr)
   CACHE  *cptr;
 {
-  Private int LRUPutTop2();
-
   return LRUPutTop2(cptr, TRUE);
 }
   
-Private int
-LRUPutTop2(cptr, f)
-     CACHE  *cptr;
-     int    f;
-{
-  CACHE       *cptr_f;
-  FILE_Port   port;
-  int         val;
-
-  cptr_f              = CacheLRUList.l_forw;
-  cptr->l_forw        = cptr_f;
-  cptr_f->l_back      = cptr;
-  cptr->l_back        = &CacheLRUList;
-  CacheLRUList.l_forw = cptr;
-
-  val = 0;
-  if (f == TRUE){
-    port = cptr->port;
-    if (VFFM_Internal_Open(port) < 0)
-      val = -1;
-  }
-
-  return val; 
-}
-
 
 Private int 
 LRUDeleteTail()
