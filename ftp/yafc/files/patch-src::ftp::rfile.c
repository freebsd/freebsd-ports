--- src/ftp/rfile.c.orig	Thu May 20 20:10:52 2004
+++ src/ftp/rfile.c	Sun May 23 21:49:54 2004
@@ -439,7 +439,11 @@
         free(saved_field[0]);
         f->owner = saved_field[1];
         f->group = saved_field[2];
+#if 0
         f->size = atoll(saved_field[3]);
+#else
+        f->size = strtoll(saved_field[3], NULL, 10);
+#endif
         free(saved_field[3]);
         m = saved_field[4];
         NEXT_FIELD2;
@@ -453,7 +457,11 @@
         free(saved_field[0]);
         f->owner = saved_field[1];
         f->group = xstrdup("group");
+#if 0
         f->size = atoll(saved_field[2]);
+#else
+        f->size = strtoll(saved_field[2], NULL, 10);
+#endif
         free(saved_field[2]);
         m = saved_field[3];
         d = saved_field[4];
@@ -465,7 +473,11 @@
         f->nhl = 0;
         f->owner = xstrdup("owner");;
         f->group = xstrdup("group");
+#if 0
         f->size = atoll(saved_field[1]);
+#else
+        f->size = strtoll(saved_field[1], NULL, 10);
+#endif
         free(saved_field[1]);
         m = saved_field[2];
         d = saved_field[3];
@@ -480,7 +492,11 @@
             free(saved_field[0]);
             f->owner = saved_field[1];
             f->group = saved_field[2];
+#if 0
             f->size = atoll(saved_field[3]);
+#else
+            f->size = strtoll(saved_field[3], NULL, 10);
+#endif
             free(saved_field[3]);
             free(saved_field[4]);
 
@@ -624,7 +640,11 @@
         f->perm[0] = 'd';
         f->size = 0L;
     } else {
+#if 0
         f->size = (unsigned long long)atoll(e);
+#else
+        f->size = (unsigned long long)strtoll(e, NULL, 10);
+#endif
     }
 
     f->nhl = 1;
@@ -686,7 +706,11 @@
              * FTP" Internet draft, but PureFTPd uses it for some
              * reason for size of directories
              */
+#if 0
             f->size = atoll(value);
+#else
+            f->size = strtoll(value, NULL, 10);
+#endif
         else if(strcasecmp(factname, "type") == 0) {
             if(strcasecmp(value, "file") == 0)
                 isdir = false;
