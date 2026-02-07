--- library.c.orig	2024-06-25 01:59:59 UTC
+++ library.c
@@ -603,12 +603,13 @@ int library_import(struct library *li, const char *sca
     char *cratename, *pathname;
     struct crate *crate;
 
-    pathname = strdupa(path);
+    pathname = strdup(path);
     cratename = basename(pathname); /* POSIX version, see basename(3) */
     assert(cratename != NULL);
 
     crate = malloc(sizeof *crate);
     if (crate == NULL) {
+        free(pathname);
         perror("malloc");
         return -1;
     }
@@ -619,11 +620,13 @@ int library_import(struct library *li, const char *sca
     if (add_crate(li, crate) == -1)
         goto fail_crate;
 
+    free(pathname);
     return 0;
 
 fail_crate:
     crate_clear(crate);
 fail:
+    free(pathname);
     free(crate);
     return -1;
 
