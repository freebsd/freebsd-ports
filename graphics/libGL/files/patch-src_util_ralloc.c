--- src/util/ralloc.c.orig	2016-11-28 15:34:30 UTC
+++ src/util/ralloc.c
@@ -315,6 +315,7 @@ ralloc_parent(const void *ptr)
 
 static void *autofree_context = NULL;
 
+__attribute__((destructor))
 static void
 autofree(void)
 {
@@ -326,7 +327,6 @@ ralloc_autofree_context(void)
 {
    if (unlikely(autofree_context == NULL)) {
       autofree_context = ralloc_context(NULL);
-      atexit(autofree);
    }
    return autofree_context;
 }
