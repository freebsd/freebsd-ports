--- FastTree-2.1.10.c.orig	2017-12-04 15:09:11 UTC
+++ FastTree-2.1.10.c
@@ -8759,7 +8759,7 @@ double pnorm(double x)
 
 void *mymalloc(size_t sz) {
   if (sz == 0) return(NULL);
-  void *new = malloc(sz);
+  void *new = aligned_alloc(16, sz);
   if (new == NULL) {
     fprintf(stderr, "Out of memory\n");
     exit(1);
