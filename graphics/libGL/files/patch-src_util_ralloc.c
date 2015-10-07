--- src/util/ralloc.c.orig	2015-08-07 17:36:03 UTC
+++ src/util/ralloc.c
@@ -311,6 +311,7 @@ ralloc_parent(const void *ptr)
 
 static void *autofree_context = NULL;
 
+__attribute__((destructor))
 static void
 autofree(void)
 {
@@ -322,7 +323,6 @@ ralloc_autofree_context(void)
 {
    if (unlikely(autofree_context == NULL)) {
       autofree_context = ralloc_context(NULL);
-      atexit(autofree);
    }
    return autofree_context;
 }
