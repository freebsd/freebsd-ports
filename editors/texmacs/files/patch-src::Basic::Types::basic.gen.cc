--- src/Basic/Types/basic.gen.cc.orig	Sun Nov 24 20:58:54 2002
+++ src/Basic/Types/basic.gen.cc	Sun Nov 24 20:59:24 2002
@@ -26,72 +26,6 @@
 
 extern int large_uses;
 
-void*
-operator new (register size_t s)
-{
-  register void* ptr;
-  s= (s+ WORD_LENGTH+ WORD_LENGTH_INC)&WORD_MASK;
-  if (s<MAX_FAST) {
-    ptr= alloc_ptr(s);
-    if (ptr==NULL) ptr= enlarge_malloc (s);
-    else alloc_ptr(s)= ind(ptr);
-  }
-  else {
-    ptr= safe_malloc (s);
-    large_uses += s;
-  }
-  *((size_t *) ptr)=s;
-  return (void*) (((char*) ptr)+ WORD_LENGTH);
-}
-
-void
-operator delete (register void* ptr)
-{
-  ptr= (void*) (((char*) ptr)- WORD_LENGTH);
-  register size_t s= *((size_t *) ptr);
-  if (s<MAX_FAST) {
-    ind(ptr)    = alloc_ptr(s);
-    alloc_ptr(s)= ptr;
-  }
-  else {
-    free (ptr);
-    large_uses -= s;
-  }
-}
-
-void*
-operator new[] (register size_t s)
-{
-  register void* ptr;
-  s= (s+ WORD_LENGTH+ WORD_LENGTH_INC)&WORD_MASK;
-  if (s<MAX_FAST) {
-    ptr= alloc_ptr(s);
-    if (ptr==NULL) ptr= enlarge_malloc (s);
-    else alloc_ptr(s)= ind(ptr);
-  }
-  else {
-    ptr= safe_malloc (s);
-    large_uses += s;
-  }
-  *((size_t *) ptr)=s;
-  return (void*) (((char*) ptr)+ WORD_LENGTH);
-}
-
-void
-operator delete[] (register void* ptr)
-{
-  ptr= (void*) (((char*) ptr)- WORD_LENGTH);
-  register size_t s= *((size_t *) ptr);
-  if (s<MAX_FAST) {
-    ind(ptr)    = alloc_ptr(s);
-    alloc_ptr(s)= ptr;
-  }
-  else {
-    free (ptr);
-    large_uses -= s;
-  }
-}
-
 bool
 debug (int which, bool write_flag) {
   static int debug_status= 0;
