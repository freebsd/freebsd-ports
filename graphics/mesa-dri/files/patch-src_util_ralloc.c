--- src/util/ralloc.c.orig	2017-04-01 15:33:37 UTC
+++ src/util/ralloc.c
@@ -338,6 +338,7 @@ ralloc_parent(const void *ptr)
 
 static void *autofree_context = NULL;
 
+__attribute__((destructor))
 static void
 autofree(void)
 {
@@ -349,7 +350,6 @@ ralloc_autofree_context(void)
 {
    if (unlikely(autofree_context == NULL)) {
       autofree_context = ralloc_context(NULL);
-      atexit(autofree);
    }
    return autofree_context;
 }
