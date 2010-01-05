--- ./medialib.c.orig	2010-01-04 03:17:55.000000000 +0100
+++ ./medialib.c	2010-01-05 18:32:53.000000000 +0100
@@ -287,7 +287,8 @@
           * last extracted meta-info from it (otherwise we ignore)
           */
 
-         if (sb.st_mtim.tv_sec > mdb.library->files[i]->last_updated) {
+         //if (sb.st_mtim > mdb.library->files[i]->last_updated) {
+         if (sb.st_mtime > mdb.library->files[i]->last_updated) {
             mi = meta_extract(filename);
 
             if (mi == NULL) {
@@ -385,7 +386,7 @@
             if (idx != -1) {
                /* file already exists in library database - update */
 
-               if (ftsent->fts_statp->st_mtim.tv_sec >
+               if (ftsent->fts_statp->st_mtime >
                    mdb.library->files[idx]->last_updated) {
 
                   /* file has been modified since we last extracted info */
